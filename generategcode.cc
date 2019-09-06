#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <cmath>
#include <memory.h>
#include <vector>
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
		if (cursor == 0)
			return;
		if (cursor > size) {
			::write(fd, buffer, size);
			cursor -= size;
			memcpy(buffer, buffer+size, cursor);
		} else {
			::write(fd, buffer, cursor);
			cursor = 0;
		}
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
#if 0
		// this should not be possible any more
    if (d1 > 10) {
      cout << "Error in digit " << d1 << '\n';
    }
#endif
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
	void writeInt(int v) {
		if (v < 0) {
			write('-');
			v = -v;
		}
		
		char ibuf[13];
		ibuf[12] = '\0';
		int i = 11;
	  do {
			ibuf[i--] = v % 10;
			v /= 10;
		} while (v > 0);
		for (i++; i < 12; i++)
			buffer[cursor++] = '0' + ibuf[i];
	}
public:
  void writeG1XYE(float x, float y, float e) {
    write("G1 "); writeXYE(x,y,e); newLineCheckBuf();
  }
  void writeG0XY(float x, float y) {
    write("G0 "); writeXY(x,y);  newLineCheckBuf();
  }
  void writeG0Z(float z) {
    write("G0 "); write('Z'); write6_2(z); newLineCheckBuf();
  }
  void writeG0XYZ(float x, float y, float z) {
    write("G0 "); writeXY(x,y); write(' '); write('Z'); write6_2(z); newLineCheckBuf();
  }
	void writeLayer(int layer) {
		write(";layer "); writeInt(layer); write('\n');
	}
};

const double PI = 3.14159265358979;

class Path2d {
private:
	float zmin, zmax; // layers in which to draw this path
public:
	void setZ(float min, float max) { zmin = min, zmax = max; }
	bool containsZ(float z) const {
		return zmin <= z && z <= zmax;
	}
	double getZMin() const { return zmin; }
	double getZMax() const { return zmax; }
	virtual void xy(double t, double& x, double& y) const = 0;
	virtual ~Path2d() {}
};

class GenerateGCode {
private:
  FastBuf<32768> buf;
  float curx,cury; // current x and y location, used to compute how far each extrude is
                   //and therefore how much to extrude
  float z;         // current z location
  float e;         // absolute extrusion value
  float extrusionCoef; // how much to extrude per unit distance. Should be based on thickness of desired bead
                       // and thickness of the filament. Oddly we can't a difference when we change
	vector<const Path2d*> paths;
	double startT;
public:
  GenerateGCode(const char pre[], const char filename[]) :
    buf(filename), extrusionCoef(0.05), curx(0), cury(0), z(0) {
    ifstream f(pre);
    char buffer[4096];
    while (f.getline(buffer, sizeof(buffer)), !f.eof()) {
      buf.write(buffer); buf.write('\n');
    }
    
  }
	~GenerateGCode() {
		end();
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
  void nextLayer(float dz) {
    z += dz;
    buf.writeG0Z(z);
  }

	void end() {
		buf.writeG0XYZ(0, cury, z+10);
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
			buf.writeLayer(i);
      circle(xc, yc, r, n);
      nextLayer(dz, xc+r, yc);
    }
  }
  template<typename CoordFunc>
  void extrude(int numSteps, int layers, double dz, const CoordFunc& f) {
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
	void add(Path2d* p, float zmin, float zmax) {
		p->setZ(zmin, zmax);
		paths.push_back(p);
	}
	
	void draw(const Path2d* s, int numSteps) {
		double x0, y0;
		s->xy(0, x0,y0);
		moveTo(x0,y0);
		double t = startT;
		const double dt = 2*PI / numSteps;
		double x,y;
		for (int j = 0; j <= numSteps; j++, t += dt) {
			s->xy(t, x,y);
			extrudeTo(x, y);
		}
	}
	void drawLayer(int layerNum, int numPoints, double z) {
		startT = fmod(layerNum * PI/2, 2*PI);
		for (auto p : paths) {
			if (p->containsZ(z))
				draw(p, numPoints);
		}
	}
};


class Petals : public Path2d {
private:
  double xc,yc;    //center
  double rx, ry;   //radii of ellipse
  double petalAmp; // amplitude of wave superimposed on the circle edge
  int    numWaves; // number of waves per circle
public:
  Petals(double xc, double yc, double rx, double ry, double petalAmp, int numWaves) :
    xc(xc), yc(yc), rx(rx), ry(ry), petalAmp(petalAmp), numWaves(numWaves) {}

  const char* getComment() const { return "; Petals\n"; }
  void xy(double t, double& x, double& y) const {
		double e = ry / rx;
    double rt = petalAmp * cos(numWaves * t);
    x = xc + rx * cos(t) + petalAmp * cos(numWaves*t);
		y = yc + ry * sin(t) + petalAmp * e * sin(numWaves*t);
  }
};

double bump(double x, double amp, double dutyCycle) {
	if (x < dutyCycle) {
		return sin(x * (2 * PI / dutyCycle));
	}
	return 0;
}

class Connector {
private:
	struct Line {
		float x1,y1, x2,y2;
		Line(float x1, float y1, float x2, float y2)
			: x1(x1), y1(y1), x2(x2),y2(y2) {}
	};
	static double dist(const Line& L1, const Line& L2) {
		double dx = L2.x1-L1.x2, dy = L2.y1 - L1.y2;
		return sqrt(dx*dx + dy*dy);
	}
	
	float xMin, xMax, yMin, yMax;
	vector<Line> points;
	void addMinMax(float x1, float x2, float& xMin, float& xMax) {
		if (x1 > x2) {
			if (x1 > xMax)
				xMax = x1;
			if (x2 < xMin)
				xMin = x1;
		} else {
			if (x2 > xMax)
				xMax = x2;
			if (x1 < xMin)
				xMin = x1;
		}
	}
public:
	Connector() { points.reserve(1024); }
	void add(const Path2d* p1, const Path2d* p2, int numConnections, double startAngle) {
		double t = startAngle;

		//		double dist =0;
		for (int i = 0; i < numConnections; i++, t += 2*PI / numConnections) {
			double x1,y1, x2,y2;
			p1->xy(t, x1,y1); 			p2->xy(t, x2,y2);
			addMinMax(x1,x2, xMin, xMax);
			addMinMax(y1,y2, yMin, yMax);
			points.push_back(Line(x1,y1,x2,y2));
		}
	}
	void sort() {
		constexpr int n = 4;
		double dx = (xMax - xMin) / n, dy = (yMax - yMin) / n;
		const double invDx = 1 / dx, invDy = 1 / dy;
		const double eps = 1e-10; //(xMin+yMin) / 1e10;
		const double yMinEps = yMin + eps, xMinEps = xMin + eps;
		vector<Line> grid[n*n];
		for (int i = 0; i < points.size(); i++) {
			int row = int((points[i].y1 - yMinEps)) * invDy;
			int col = int((points[i].x1 - xMinEps)) * invDx;
			int ind = row*n + col;
			grid[ind].push_back(points[i]);
		}
		#if 0
		for (int i = 0; i < points.size(); i++) {
			vector<Line>& line = grid[i];
			for (int j = 0; j < line.size(); j++)
				;
		}
		#endif
		points.clear();
		for (int i = 0; i < n*n; i++) {
			cout << grid[i].size() << '\n';
			for (const auto& line : grid[i]) {
				points.push_back(line);
			}
		}
		for (int i = 0; i < points.size(); i++) {
			double d = dist(points[i], points[i+1]), d2;
			for (int j = i + 2; j < points.size(); j++) 
				if ((d2 = dist(points[i], points[j])) < d) {
					swap(points[i+1], points[j]);
					d = d2;
				}
		}
	}
	
	void draw(GenerateGCode& gc) {
		for (int i = 0; i < points.size(); i++) {
			gc.moveTo(points[i].x1, points[i].y1);
			gc.extrudeTo(points[i].x2, points[i].y2);
		}
	}
};

class SoundBarrier : public Path2d {
private:
	double cx, cy;
	double rx, ry; // radii of ellipse in each dir
	int numBumps;         // number of smaller superimposed bumps
	double bumpAmplitude; // amplitude of those bumps
	double dutyCycle;     // sharpness of those bumps
public:
	SoundBarrier(	double cx, double cy, double rx, double ry,
								int numBumps,
								double bumpAmplitude, double dutyCycle)
		: cx(cx), cy(cy), rx(rx), ry(ry), numBumps(numBumps),
			bumpAmplitude(bumpAmplitude), dutyCycle(dutyCycle) {}
  const char* getComment() const { return "; SoundBarrier\n"; }

	void xy(double t, double& x, double& y) const {
		double rt = rx*cos(t) + ry*sin(t) + bumpFunc(fmod(t, 2*PI/numBumps));
		x = cx + rt * cos(t); y = cy + rt * sin(t);
	}

	double bumpFunc(double t) const {
		if (t < dutyCycle)
			return bumpAmplitude * sin(t / dutyCycle);
		return 0;
	}
};

int main(int argc, char* argv[]) {
	const char* outFile = argc >= 2 ? argv[1] : "test.gcode";
  GenerateGCode gcode("pre.gcode", outFile);
  double r = 20;
  const int numSteps = 160;
  const double dz = 0.2;
	SoundBarrier barrier(100,100,  20,30,
											 4,
											 3.0,
											 0.25);
	//  gcode.extrude(numSteps, numLayers, dz, barrier);
	//  gcode.cylinder(100.0, 100.0, r, numSteps, dz, numLayers);
	
	//	Petals p(100.0, 100.0, 20, 3, 4);
	//gcode.extrude(numSteps, numLayers, dz, p);

	double cx = 100, cy = 100;
	constexpr int concentric = 6;
	constexpr int numConnections = 4;
	Petals* petals[concentric];
	Connector conn;
	for (int i = 0; i < concentric; i++) {
		gcode.add(petals[i] = new Petals(cx,cy, 30.0 + 2*i, 40.0 + 2*i, 1.0, 16),
							0, 12 + 2*i);
		
		if (i > 0)
			conn.add(petals[i], petals[i-1], 4, i % 2 * (PI/4));
	}
	conn.sort();
	double maxZ = 12 + 2*5;
  const int numLayers = maxZ / dz;
	double z = 0;
	for (int i = 0; i < numLayers; i++, z += dz) {
		gcode.drawLayer(i, numSteps, z);
		if (i < numLayers/2)
			conn.draw(gcode);
		gcode.nextLayer(dz);
	}
}
