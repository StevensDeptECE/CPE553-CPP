#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <cmath>
using namespace std;

typedef double (*FuncOneVar)(double x);

template<uint32_t size>
class FastBuf {
private:
  constexpr static uint32_t OVERFLOW = 128; // extra space in case of overwriting
  int fd;
  char buffer[size + OVERFLOW];
  uint32_t cursor;
  
public:
  FastBuf(const char filename[]) : cursor(0) {
    fd = open(filename, O_WRONLY|O_CREAT, 0644);
    if (fd < 0)
      throw "outahere";
  }
  ~FastBuf() {
    flush();
    close(fd);
  }
  void flush() {
    ::write(fd, buffer, cursor);
    cursor = 0;
  }
  
  void write(const char* t) {
    while (*t != '\0')
      buffer[cursor++] = *t++;
  }

  void write(char c) {
    buffer[cursor++] = c;
  }
  // write a floating point number with 4 digits before the decimal and 2 after
  void write6_2(float v) {
    if (v < 0) {
      buffer[cursor++] = '-';
      v = -v;
    }
    uint32_t whole = uint32_t(v);
    v -= whole; // v is now fractional part
    if (whole < 10) {
      buffer[cursor++] = '0' + whole;
    } else {
      if (whole >= 100) {
        if (whole >= 1000) {
          int d1 = whole / 1000;
          buffer[cursor++] = '0' + d1;
          whole -= d1 * 1000;
        }
        int d2 = whole / 100;
      buffer[cursor++] = '0' + d2;
      whole -= d2 * 100;
      }
      int d3 = whole / 10;
      buffer[cursor++] = '0' + d3;
      whole -= d3 * 10;
      buffer[cursor++] = '0' + whole;
    }
    
    whole = uint32_t(v * 100); // take the top 2 digits of fractional part
    int d1 = whole / 10;
    whole -= d1 * 10;
    if (d1 == 0 && whole == 0)
      return;
    buffer[cursor++] = '.';
    if (d1 > 10) {
      cout << "Error in digit " << d1 << '\n';
    }
    buffer[cursor++] = '0' + d1;
    buffer[cursor++] = '0' + whole;
  }
private:
  void writeXY(float x, float y) { write('X'); write6_2(x); write(' '); write('Y'); write6_2(y); }
  void writeXYE(float x, float y, float e) { writeXY(x,y); write(' '); write('E'); write6_2(e); }
  void writeXYEF(float x, float y, float e, float f) {
    writeXYE(x,y,e); write(' '); write('f'); write6_2(e);
  }
  void newLineCheckBuf() {
    write('\n');
    if (cursor > size)
      flush();
  }   
public:
  void writeG1XYE(float x, float y, float e) {
    write("G1 "); writeXYE(x,y,e); newLineCheckBuf();
  }
  void writeG0XY(float x, float y) {
    write("G0 "); writeXY(x,y);  newLineCheckBuf();
  }
  void writeG0XYZ(float x, float y, float z) {
    write("G0 "); writeXY(x,y); write(' '); write('Z'); write6_2(z); newLineCheckBuf();
  }
};

const double PI = 3.14159265358979;

class GenerateGCode {
private:
  FastBuf<32768> buf;
  float curx,cury; // current x and y location, used to compute how far each extrude is
                   //and therefore how much to extrude
  float z;         // current z location
  float e;         // absolute extrusion value
  float extrusionCoef; // how much to extrude per unit distance. Should be based on thickness of desired bead
                       // and thickness of the filament. Oddly we can't a difference when we change
public:
  GenerateGCode(const char pre[], const char filename[]) :
    buf(filename), extrusionCoef(0.05), curx(0), cury(0), z(0) {
    ifstream f(pre);
    char buffer[4096];
    while (f.getline(buffer, sizeof(buffer)), !f.eof()) {
      buf.write(buffer); buf.write('\n');
    }
    
  }
  void extrudeTo(float x, float y) {
    double dx = x-curx, dy = y-cury;
    double dist = sqrt(dx*dx + dy*dy);
    e += dist * extrusionCoef;
    curx = x, cury = y;
    buf.writeG1XYE(x,y,e);
  }
  
  void moveTo(float x, float y) {
    curx = x, cury = y;
    buf.writeG0XY(x,y);
  }
  void nextLayer(float dz, float x, float y) {
    z += dz;
    curx = x, cury = y;
    buf.writeG0XYZ(x,y,z);
  }
  
  void circle(double xc, double yc, double r, int n) {
    double t = 0;
    moveTo(xc + r,yc);
    double dt = 2 * PI / n;
    for (int i = 0; i <= n; i++, t += dt) {
      extrudeTo(xc + r*cos(t), yc + r*sin(t));
    }
  }
  
  void wavyCircle(double r, int n, double r2, int numBumps) {
    double t = 0;
    moveTo(r,0);
    double dt = 2 * PI / n;
    for (int i = 0; i < n; i++, t += dt) {
      double rt = r + r2*cos(numBumps*t);
      extrudeTo(rt*cos(t), rt*sin(t));
    }
  }
  void cylinder(double xc, double yc, double r, int n, double dz, int layers) {
    for (int i = 0; i < layers; i++) {
      circle(xc, yc, r, n);
      nextLayer(dz, xc+r, yc);
    }
  }
  template<typename CoordFunc>
  void funkyShape(int numSteps, int layers, double dz, const CoordFunc& f) {
    buf.write(f.getComment());
    for (int i = 0; i < layers; i++) {
      double t = 0;
      const double dt = 2*PI / numSteps;
      double x0 = f.x(0), y0 = f.y(0);
      moveTo(x0, y0);
      for (int j = 0; j < numSteps; j++, t += dt)
        extrudeTo(f.x(t), f.y(t));
      nextLayer(dz, x0, y0);
    }
  }
};

class Petals {
private:
  double xc,yc;    //center
  double r;        //radius of circle
  double petalAmp; // amplitude of wave superimposed on the circle edge
  int    numWaves; // number of waves per circle
public:
  Petals(double xc, double yc, double r, double petalAmp, int numWaves) :
    xc(xc), yc(yc), r(r), petalAmp(petalAmp), numWaves(numWaves) {}

  const char* getComment() const { return "; Petals\n"; }
  double x(double t) const {
    double rt = r + cos(numWaves * t);
    return rt*cos(t);
  }
  double y(double t) const {
    double rt = r + cos(numWaves * t);
    return rt*sin(t);
  }
};
  


int main() {
  GenerateGCode gcode("pre.gcode", "test.gcode");
  double r = 20;
  const int numSteps = 16;
  const int numLayers = 5;
  const double dz = 0.2;
  gcode.cylinder(100.0, 100.0, r, numSteps, dz, numLayers);
  //  Petals p(100.0, 100.0, 20, 3, 4);
  //  gcode.funkyShape(numSteps, numLayers, dz, p);
}
