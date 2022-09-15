#include <iostream>
#include <fstream>
using namespace std;
#include "Graph2D.hh"
#include <cmath>
using namespace std;
void testScales() {
  LinearScale s(0, 3, -20, 20);
  LogScale s2(0, 100, 0, 200);
  cout << s.scale(0) << "\n";
  cout << s.scale(3) << "\n";
  cout << s.scale(1.5) << "\n";
  
  cout << "test log scale: \n";
  double x = 1;
  for (int i = 0; i < 7; i++, x += .5) {
    cout << s2.scale(x) << "\n";
  }
}

void testProgrammatic() {
}

void testMap() {
  ifstream file("conf/map.conf");
  Document doc(file);
  GraphStyle gs(file);
  ScaleInfo scale(file, 500, 500, gs);
  Map map(doc, scale, "data/fullnycoast.dat");
  map.draw();
  doc.add(map);
}

void testReadFromFile() {
  ifstream file("conf/test.conf");
  Document doc(file);
  GraphStyle gs(file);
  Graph2D g(doc, gs, file);
  double x[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  double y[] = {1.1, 2.1, 3.0, 2.2, 2.5, 2.6, 2.4, 2.5, 2.9, 3.0};
  double y2[] = {2.1, 5.1, 8.0, 5.2, 6.5, 6.6, 5.4, 6.5, 5.9, 4.0};
  double wind[] = {2.5, 5.0, 15, 10, 12.5, 11.0, 13, 6, 4, 2.5};
  double dir[] = {0, 30, 60, 90, 135, 155, 280, 320, 340, 350};
  LineStyle black(0, 0,0,0, 0,0);
  LineStyle reddash(2, 1,0,0, 5,5);
  FillStyle redf(1,0,0);
  FillStyle arrowStyle(0,0,0);

  //g.addDataLine(x, y, sizeof(x)/sizeof(double), "salinity", black);
  g.addDataLineAndMarkers(x, y, sizeof(x)/sizeof(double), "temperature", "/diamond", 4, black, redf);
  g.addMarkers(x, y2, sizeof(x)/sizeof(double), "temperature",  "/diamond", 4,redf);
  g.addVectors(x, wind, dir, sizeof(x)/sizeof(double), "wind", 30, "/a1", arrowStyle);
  g.draw();
  g.horizontalLine(10, black);
  g.verticalLine(10, reddash);
  doc.add(g);
}

#if 0
void queryxy(Connection& con, const char sql[], vector<double>& x, vector<double>& y) {
  // Retrieve a subset of the sample stock table set up by resetdb
  Query query = con.query();
  query << sql;
  Result res = query.store();
  cerr << "SQL: " << sql << "\n";
  Row::size_type i;
  if (res) {
    Row row;
    ColData temp_val;
    for (i = 0; row = res.at(i); ++i) {
      temp_val = row.at(0);
      double val = temp_val;
      //      cerr << val << "\n";
      x.push_back(i);
      y.push_back(val);
    }
  }
}
#endif

#if 0
void testReadFromDB() {
  ifstream file("conf/testdb.conf");
  Document doc(file);
  GraphStyle gs(file);
  Graph2D g(doc, gs, file);
  LineStyle black(0, 0,0,0, 0,0);
  LineStyle reddash(2, 1,0,0, 5,5);
  FillStyle redf(1,0,0);
  FillStyle arrowStyle(0,0,0);
  Connection con(false);
  con.connect("dl", "atlas2", "dl_reader", "BIGre3der", 3306);
  if (!con) {
    cout << "database connection failed" << endl;
    return ;
  }

  vector<double> x;
  vector<double> y;
  queryxy(con, "select val from ext_data where sid = 'N001' and param = 'ATMP' and dt > '2007-05-28 10:00:00'", x, y);
  g.addDataLine(x, y,  "airtemp", black);


 //g.addDataLine(x, y, sizeof(x)/sizeof(double), "salinity", black);
  //g.addDataLineAndMarkers(x, y, sizeof(x)/sizeof(double), "temperature", "/diamond", 4, black, redf);
  //g.addMarkers(x, y2, sizeof(x)/sizeof(double), "temperature",  "/diamond", 4,redf);
  //g.addVectors(x, wind, dir, sizeof(x)/sizeof(double), "wind", 30, "/a1", arrowStyle);
  g.draw();
  g.horizontalLine(20, black);
  g.verticalLine(10, reddash);
  doc.add(g);

  Graph2D g2(doc, gs, file);
  vector<double> x2;
  vector<double> y2;
  queryxy(con, "select val from ext_data where sid = 'U206' and param = 'WTMP' and dt > '2007-05-28 10:00:00'", x2, y2);
  g2.addDataLine(x2, y2,  "salinity", black);
  g2.draw();
  doc.add(g2);

  Graph2D g3(doc, gs, file);
  vector<double> x3;
  vector<double> y3;
  queryxy(con, "select val from ext_data where sid = 'U206' and param = 'SALT' and dt > '2007-05-28 10:00:00'", x3, y3);
  g3.addDataLine(x3, y3,  "salinity", black);
  g3.draw();
  doc.add(g3);

}
#endif

// test laying out lots of little graphs on a page (See tufte.com)
void testSparklines() throw (char*const){
  ifstream file("conf/sparklines.conf");
  Document doc(file);
  GraphStyle gs(file);
// the 500 is arbitrary just to keep it happy until the layout sets the actual width/height
  ScaleInfo scaling(file, 500, 500, gs); 
  double x[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  double y[] = { 1.1, 2.1, 3.0, 2.2, 2.5, 2.6, 2.4, 2.5, 2.9, 3.0 };
  LineStyle black(0, 0,0,0, 0,0);
  LineStyle reddash(2, 1,0,0, 5,5);
  FillStyle redf(1,0,0);
  FillStyle arrowStyle(0,0,0);


  for (int i = 0; i < 12; i++) {
    Graph2D g(doc, gs, scaling); // at this point, actual width/height is known, scales recompute
    g.addDataLineAndMarkers(x, y, sizeof(x)/sizeof(double), "temperature", "/diamond", 4, black, redf);
    g.draw();
    doc.add(g);
  }
}

class TestDrawable : public Component {
public:
  void draw() {
    LineStyle red(1, 1,0,0, 0,0);
    LineStyle green(1, 0,1,0, 0,0);
    LineStyle blue(1, 0,0,1, 0,0);
    LineStyle dashblue(2, 0,0,1, 5,5);
    LineStyle black(5, 0,0,0, 0,0);
    FillStyle gray(0.5,0.5,0.5);
    FillStyle darkblue(0,0,0.7);
    
    fillRect(gray, 0,0,50,50);
    fillRoundRect(darkblue, 200,0,300,100, 25);
    drawRoundRect(red, 200,300,300,400, 20);
    {
      double x[] = {   0, 500, 100, 400, 200, 300 };
      double y[] = { 500, 400, 300, 200, 100, 0 };
      double scale[] = { 4, 4, 4, 4, 4, 4 };
      drawPolyline(black, x, y, sizeof(x)/sizeof(double));
      translateScalePlot(x, y, scale, sizeof(x)/sizeof(double), "/circle");
    }
    line(dashblue, 0,0, 100,100);
    TextStyle big(0,0.2,0.2, "Times", 20);
    applyStyle(big);
    text(200,200, "this is a test");
    TextStyle small(1,0.2,0.2, "Times", 8);
    text(small, 200, 300, "this is a smaller test");

    {
      double x[] = { 100, 150, 200, 250, 300, 350, 400, 450, 500};
      double y[] = { 500, 500, 500, 500, 500, 500, 500, 500, 500};
      double scale[] = { 10, 15, 20, 25, 30, 35, 30, 30, 30};
      double rot[] = { 0, 10, 20, 30, 45, 60, 75, 90, 180};
      //double rot[] = { 0, 45, 90, 135, 180, 225, 270, 315, 0};

      translateRotateScalePlot(x, y, scale, rot,sizeof(x)/sizeof(double), "/a1");
    }

    {
      double x[] = { 100, 110, 140,  90, 110, 100};
      double y[] = { 600, 610, 600, 590, 580, 590};
      fillPolygon(x, y, sizeof(x)/sizeof(double));
      
    }

    drawGrid(0.0, 200.0, 5, 0.0, 200.0, 10);
    drawCircle(300, 450, 20);
    fillCircle(450, 450, 20);
    applyStyle(black);
    drawTicksX(0.0, 500.0, 6, 250.0, 10.0, 11, 5.0);
    drawTicksY(0.0, 500.0, 6, 250.0, 10.0, 11, 5.0);
  }
  TestDrawable(Document& doc) : Component(doc) {
    doc.add(*this);
  }
};

void testPrimitives() {
  ifstream file("conf/test.conf");
  Document doc(file);
  TestDrawable d(doc);
}

class Test3D : public Component3D {
public:
  Test3D(Document& doc, const Matrix4& m) : Component3D(doc, m) {
    doc.add(*this);
  }
  void draw() {
    LineStyle black(1, 0,0,0, 0,0);
    applyStyle(black);
    box(0,0,0,   100,100,100);
  }
};
void test3D() {
  ifstream file("conf/test.conf");
  Document doc(file);
  const double TO_RAD = M_PI/180;
  const double deg45 = 45 * TO_RAD, deg30 = 30 * TO_RAD;
  Matrix4 m = Matrix4::rotateX(deg45) * Matrix4::rotateY(deg30);
  m.trans(100,100,0);
      Test3D d(doc, m);
      
  for (double y = 0, ty = 0; y < 30; y += 10, ty += 100) {
    for (double x = 0, tx = 0; x < 50; x += 10, tx += 100) {
      Matrix4 m = Matrix4::rotateX(x * TO_RAD) * Matrix4::rotateY(y * TO_RAD);
      m.trans(tx, ty, 0);
      cerr <<"rot:" << x << "," << y << "\n" << m;
      Test3D d(doc, m);
    }
  }

};

int main() {
  try {
    //testMap();
    testSparklines();
    //testReadFromFile();
    //    testReadFromDB();
    //testPrimitives();
    //test3D();
  } catch (char* msg) {
    cout << "caught exception " << msg << " terminating.\n";
  }
}
