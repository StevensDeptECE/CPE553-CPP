#ifndef GRAPH2D_HH
#define GRAPH2D_HH

#include "StringBuffer.hh"
#include <cmath>

#include "utilities.hh"
#include "parse.hh"
#include <vector>


using namespace std;
using namespace util;

// Base class for scaling data
class Scale {
protected:
  double m, a;
  Scale() {} // only for internal efficiency, do not use!!
public:
  Scale(double m_, double a_) : m(m_), a(a_) {}
  virtual double scale(double v) = 0;
  virtual double scaleOffset(double v) = 0;
  virtual bool inRange(double v) = 0;
  void scale(double x[], int n) {
    for (int i = 0; i < n; i++)
      x[i] = scale(x[i]); // TODO: verify C++ is smart enough to inline this!
  }
  void print(StringBuffer& b) const {
    b.append("Scale");
  }
  virtual void setBounds(double min, double max, double pMin, double pSize) = 0;
  static Scale& readScale(istream& s, const char name[], double pMin, double pSize) throw (char*);
};

// Linear transformation
class LinearScale : public Scale {
private:
  double min, max;
public:
  LinearScale(double min, double max, double pMin, double pSize) {
    setBounds(min, max, pMin, pSize);
  }
  LinearScale(double m_, double a_) : Scale(m_, a_) {
  }
  double scale(double x) { return m * x + a; }
  double scaleOffset(double x) { return m * x; }

  void scale(double x[], int n) {
    for (int i = 0; i < n; i++)
      x[i] = scale(x[i]); // TODO: verify C++ is smart enough to inline this!
  }

  bool inRange(double v) {
    return v >= min && v <= max;
  }

  void print(StringBuffer& b) const {
    b.append("LinearScale ").append(m).append(' ').append(a);
  }

  // create scale based on min/max in world coordinates, and pMin pSize in Page coordinates (relative to component's box)
  void setBounds(double min_, double max_, double pMin, double pSize) {
    min = min_; max = max_;
    m = pSize / (max - min);
    a = pMin - min * m;
  }
};

//Logarithmic scale
class LogScale : public LinearScale {
public:
  LogScale(double min, double max, double pMin, double pMax) : LinearScale(min, max, pMin, pMax) {}

  LogScale(double m_, double a_) : LinearScale(m_, a_) {}
  double scale(double x) { return log10(m * x + a); }
  double scaleOffset(double x) { return log10(m * x); }
  void scale(double x[], int n) {
    for (int i = 0; i < n; i++)
      x[i] = scale(x[i]); // TODO: verify C++ is smart enough to inline this!
  }
};

#if 0
// TODO: add in support for "schematic scaling"
// very cool when values span multiple ranges sparsely
// should sort by magnitude and plot everything equally 
// excellent when graphing deals with values like $1, $100, and $100,000,000
class SchematicScale {
public:
  SchematicScale() {}
  double scale(double x) { return ; }
  void scale(double x[], int n) {
    for (int i = 0; i < n; i++)
      x[i] = scale(x[i]); // TODO: verify C++ is smart enough to inline this!
  }
};
#endif

// encapsulate everything about how you draw a line, width, color, dashing
class LineStyle {
public:
  float lineWidth;
  string linecolor;
  string dashstyle;
  float x, y;
  friend istream& operator >>(istream& s, LineStyle& style) {
    float lineWidth, r, g, b, on, off;
    s >> lineWidth >> r >> g >> b >> on >> off;
    style.init(lineWidth, r, g, b, on ,off);
    return s;
  }
  void init(float lineWidth_, float r, float g, float b, float on, float off) {
    lineWidth = lineWidth;
    char buffer[256];
    sprintf(buffer, "%f %f %f", r, g, b);
    linecolor = buffer;
    if (on == 0 && off == 0) {
      dashstyle = "[] 0";
    } else {
      sprintf(buffer, "[%f %f] 1", on, off);
      dashstyle = buffer;
    }
  }

  LineStyle(float lineWidth_, float r, float g, float b, float on, float off) {
    init(lineWidth_, r, g, b, on, off);
  }
  LineStyle() {
    init(1, 0,0,0, 0,0);
  }
};

inline void expectLineStyle(istream& s, const char name[], LineStyle& lineStyle) {
  char buffer[256];
  int i = expect(s, buffer, name);
  char* p = buffer+i;
  lineStyle.lineWidth = strtof(p, &p);
  i = p-buffer; // start of color
  float r = strtof(p, &p);
  float g = strtof(p, &p);
  float b = strtof(p, &p);
  char save = *p;
  *p = '\0'; // ugly hack to assign substring, thank you c++ std
  lineStyle.linecolor = string(buffer+i);
  *p = save;
  float on = strtof(p, &p);
  float off = strtof(p, &p);
  char buf2[256];
  sprintf(buf2, "[%f %f] 1", on, off);
  if (on == 0 && off == 0)
    lineStyle.dashstyle = "[] 0";
  else {
    lineStyle.dashstyle = buf2;
  }

  if (p == buffer+i) {
    throw "format exception";
  }
}

// represent everything about filling an area, color for now, should also pattern eventually
class FillStyle {
public:
  string color;
  FillStyle(const string& color_) : color(color_) {}
  FillStyle(float r, float g, float b) {
    init(r, g, b);
  }

  void init(float r, float g, float b) {
    char buffer[256];
    sprintf(buffer, "%f %f %f", r, g, b);
    color = buffer;
  }
};

// text styles have color, font, and size of font
// note that in postscript, you don't have font weight, you just have to pick a heavier font.
class TextStyle {
public:
  string color;
  string font;
  double size;
  //  float x, y;
  friend istream& operator >>(istream& s, TextStyle& ts) {
    ts.color = expectRGB(s, "tickcolor");
    ts.font = expectString(s, "font");
    ts.size = expectDouble(s, "size");
    return s;
  }
  TextStyle(const string& color_, const string& font_, double size_) : color(color_), font(font_), size(size_) {}
  TextStyle(float r, float g, float b, const string& font_, double size_) : font(font_), size(size_) {
    char buffer[256];
    sprintf(buffer, "%f %f %f", r, g, b);
    color = buffer;
  }
  TextStyle() : color("0 0 0"), font("Helvetica"), size(12) {}
};

// base class for different kinds of layout, reminiscent of java
class Layout {
private:
  void computeUniformSize(double*& rowcolSizes, int len, double maxEdge, double minEdge, double marginSize) {
    rowcolSizes = new double[len];
    double size = (maxEdge - minEdge) / len - marginSize;
    for (int i = 0; i < len; i++) {
      rowcolSizes[i] = size;
    }
  }

public:
  double leftEdge, rightEdge, topEdge, botEdge;
  double xMargin, yMargin; // space between rows and columns
  int numCols, numRows;
  double* rowSizes;
  double* colSizes;
  int boxCount;
  Layout(double width, double height) {
    leftEdge = botEdge = 0;
    //    rightEdge = 
    rowSizes = colSizes = NULL;
    boxCount = 0;
  }
  ~Layout() {
    cerr << "freeing layout\n";
    delete [] rowSizes;
    delete [] colSizes;
  }

  Layout() {
    rowSizes = colSizes = NULL;
    numCols = numRows = 0;
    leftEdge = rightEdge = topEdge = botEdge = 0;
    xMargin = yMargin = 0;
    boxCount = 0;
  }

  Layout(double width, double height, double margin, int numCols_, int numRows_) :
    leftEdge(margin),
    botEdge(margin),
    rightEdge(width - margin),
    topEdge(height - margin),
    numCols(numCols_),
    numRows(numRows_)
  {
    set(width, height);
  }

  void set(double pageWidth, double pageHeight) {
    rightEdge = pageWidth - rightEdge;
    topEdge = pageHeight - topEdge;
    computeUniformSize(colSizes, numCols, rightEdge, leftEdge, xMargin);
    computeUniformSize(rowSizes, numRows, topEdge, botEdge, yMargin);
  }

  Layout(double width, double height, double margin, double colSizes_[], int numCols_, double rowSizes_[], int numRows_) :
    leftEdge(margin),
    botEdge(margin),
    rightEdge(width - margin),
    topEdge(height - margin),
    numCols(numCols_),
    numRows(numRows_) {
    for (int i = 0; i < numCols; i++) {
      colSizes[i] = colSizes_[i];
    }
    for (int i = 0; i < numRows; i++) {
      rowSizes[i] = rowSizes_[i];
    }
  }
  friend istream& operator >>(istream& s, Layout& layout) {
    layout.leftEdge = expectDouble(s, "leftmargin");
    layout.rightEdge = expectDouble(s, "rightmargin");
    layout.botEdge = expectDouble(s, "botmargin");
    layout.topEdge = expectDouble(s, "topmargin");
    layout.numCols = expectInt(s, "numcols");
    layout.numRows = expectInt(s, "numrows");
    layout.boxCount = 0; //expectInt(s, "boxcount");
    return s;
  }

};

// layout a rectangular component, getting the requisite information from the config file
class ComponentLayout {
public:
  FillStyle bg; // background style for the entire rectangle

  double leftMargin, botMargin, rightMargin, topMargin;
  ComponentLayout(istream& s) : bg("") {
    bg.color = expectRGB(s, "bgcolor");
    leftMargin = expectDouble(s, "leftmargin");
    rightMargin = expectDouble(s, "rightmargin");
    botMargin = expectDouble(s, "botmargin");
    topMargin = expectDouble(s, "topmargin");
  }
};

// represent all the information needed to lay out an x-y plot.
// all the values are loaded from the config file
class GraphStyle : public ComponentLayout {
public:
  FillStyle bg_graph;
  LineStyle* box_border_style;
  LineStyle tick_style;
  int num_x_ticks;
  int num_y_ticks;
  int inclusive_y_min;
  int inclusive_y_max;
  TextStyle tick_num_text_style;
  string x_tick_num_format;
  string y_tick_num_format;
  Layout layout;
  double xtick_pos;
  double ytick_pos;
  double xticknumdx;
  double xticknumy;
  double yticknumx;
  double yticknumdy;
  double tickPercent;

  GraphStyle(istream& s) throw (char*) : ComponentLayout(s), bg_graph("") {
    bg_graph.color = expectRGB(s, "bggraph");
    box_border_style = NULL;
  
    expectLineStyle(s, "tickstyle", tick_style);
    num_x_ticks = expectInt(s, "numxticks");
    num_y_ticks = expectInt(s, "numyticks");
    tickPercent = expectDouble(s, "tickpercent");
    xtick_pos = expectDouble(s, "xtickpos");
    ytick_pos = expectDouble(s, "ytickpos");
    xticknumdx = expectDouble(s, "xticknumdx");
    xticknumy = expectDouble(s, "xticknumy");
    yticknumx = expectDouble(s, "yticknumx");
    yticknumdy = expectDouble(s, "yticknumdy");
    inclusive_y_min = inclusive_y_max = false; // TODO: hardcoded for now, too lazy to do this one at the moment  
    s >> tick_num_text_style;
    x_tick_num_format = "(" + expectToken(s, "xtickfmt") + ")";
    y_tick_num_format = "(" + expectToken(s, "ytickfmt") + ")";
  }
};

// forward reference to component, because it needs Document, and C++ doesn't like that!
class Component;

// Represent a document, including page size/layout, job info
// but also loads the code to be printed before the job, the postcript library
// all my cool little postscript hacks are in graphite.ps, which is printed into the job
// everything uses the high speed StringBuffer, which is WAY faster than the default iostreams
// remember that a graph with enough detail (particularly shading) may be megabytes.
class Document {
private:
  string version;
  string pageSizeName;
  string orientation;
  double pageWidth, pageHeight;
  string title;
  string author;
  string copyright;
  string creationDate;
  int stackSize;
  StringBuffer buf;
  vector<string> libraries;
  unsigned int pageCount;
  Layout layout;


  void setPageSize() {
    if (pageSizeName == "Letter" || pageSizeName =="") {
      if (orientation == "Portrait") {
				pageWidth = 612; pageHeight = 792;
      } else {
				pageWidth = 792; pageHeight = 612;
      }
    } else if (pageSizeName == "Tabloid") {
      if (orientation == "Portrait") {
				pageWidth = 792; pageHeight = 1224;
      } else {
				pageWidth = 1224; pageHeight = 792;
      }
    } else if (pageSizeName == "Legal") {
      if (orientation == "Portrait") {
				pageWidth = 612; pageHeight = 1008;
      } else {
				pageWidth = 1008; pageHeight = 612;
      }
    }
  }

  // print this before each page
  void pageProlog() {
    buf.append("%%BeginPageSetup\n");
    buf.append("<< /PageSize [").append(pageWidth).append(' ').append(pageHeight).append("] >> setpagedevice\n");
    buf.append("<< /MaxOpStack ").append(stackSize).append(" >> setuserparams\n");
    buf.append("%%EndPageSetup\n");
  }

  // the official postscript header.  Without this, the Docucolor242 prints...nothing.
  // I'd love to know if other printers are as finicky, ghostscript is much less of a pain
  void buildHeader() {
    buf.append("%!PS-Adobe-3.0\n");
    buf.append("%%Title: ").append(title).append("\n");
    buf.append("%%For:\n");
    buf.append("%%Creator: ").append(author).append(" using Graphite Library").append(version).append("\n");
    buf.append("%%CreationDate: ").append(creationDate).append("\n");
    buf.append("%%BoundingBox: ").append(layout.leftEdge, ' ', layout.botEdge, ' ',
					 layout.rightEdge, ' ' ,layout.topEdge).append("\n");
    buf.append("%%DocumentData: Clean7Bit\n");
    buf.append("%%Orientation: ").append(orientation).append("\n");
    buf.append("%%Pages: ").append(pageCount).append("\n");
    buf.append("%%PageOrder: Ascend\n");
    buf.append("%%DocumentMedia: ").append(pageSizeName).append(' ').
      append(pageWidth).append(' ').append(pageHeight).append(" 0 () ()\n");
    buf.append("%%DocumentNeededResources\n");
    buf.append("%%DocumentProcessColors: Color\n");
    buf.append("%%EndComments\n");
    buf.append("%%BeginProlog\n");
    buf.append("%%Copyright: ").append(copyright).append("\n");
    buf.append("%%EndProlog\n");
    buf.append("%%BeginSetup\n");
    buf.append("%%EndSetup\n");
    buf.append("%%Page: (1) 1\n");
    pageProlog();
  }

  // the postscript showpage command forces the page to come out, I encapsulate just in case 
  // something else becomes necessary in the future...
  void endPage() {
    buf.append("showpage\n");
    pageCount++;
  }

  // the standard postscript epilogue.  It's all comments anyway...
  void endDocument() {
    endPage();
    buf.append("%%Trailer\n");
    buf.append("%%EOF\n");
  }
  friend class Component;  // Component and Document are tightly bound
public:

  void dateNow(); // for embedding current date/time into the document
  void computeBounds(Component& c); // computing a rectangle

  StringBuffer& getBuffer() { return buf; }

  Document(string pageSizeName_, string orientation_, string title_,
	   string author_, string copyright_, vector<string> libraries_, Layout layout_) :
    pageSizeName(pageSizeName_),
    orientation(orientation_),
    title(title_),
    author(author_),
    copyright(copyright_),
    buf(1024*1024, 16),
    layout(layout_),
    stackSize(300000)
  {
    init();
    for (int i = 0; i < libraries.size(); i++) {
      buf.readFile(libraries[i]);
    }
  }
  void init() {
    pageCount = 0;
    version = "1.0";
    setPageSize();
    layout.set(pageWidth, pageHeight);
    buildHeader();
  }

  Document(istream& s) : buf(1024*1024, 16), layout() {
    s >> *this;
  }

  ~Document() {
    endDocument();
    cout << buf;
  }
  // copying a document is not supported, which in older c++, I just indicate by not implementing them
  // you'll get a linker error if you try copying the object
  Document(const Document& orig);
  Document& operator ==(const Document& orig);

  // read in all the document information from the stream into the object
  // TODO: switch to templating, so I can use a much higher speed stream based on level 2 I/O
  friend istream& operator >>(istream& s, Document& d) {
    d.title = expectString(s, "title");
    d.author = expectString(s, "author");
    d.copyright = expectString(s, "copyright");
    d.creationDate = expectString(s, "creationdate");
    d.stackSize = expectInt(s, "stack");
    d.pageSizeName = expectString(s, "pagesize");
    d.orientation = expectString(s, "orientation");
    s >> d.layout;
    d.init();

    int numLibraries = expectInt(s, "numlibraries");
    string libraryname;
    for (int i = 0; i < numLibraries; i++) {
      getline(s, libraryname);
      //      cout << "library=" << libraryname << "\n";
      d.libraries.push_back(libraryname);
      d.buf.readFile(libraryname.c_str());
    }
    d.buf.append("%============================\n");
    return s;
  }

  // build a simple layout where margin is the same on all sides,
  // and all boxes are the same size
  void buildLayout(double margin, int numCols, int numRows) {
    layout = Layout(pageWidth, pageHeight, margin, numCols, numRows);
  }
    
  // add a graphical component to the current page
  void add(Component& d);

  // TODO: make includeEPS work
  void includeEPS(string epsfile, double x, double y);
};

// All the low-level drawing operations are encapsulated here, just like Java Component in AWT
class Drawable {
protected:
  StringBuffer& buf;
private:
  void displayArray(double x[], int n) {
    if (n == 0) {
      buf.append("[]");
      return;
    }
    buf.append('[').append(x[0]);
    for (int i = 1; i < n; i++) {
      buf.append(' ').append(x[i]);
    }
    buf.append("]");
  }
public:
  Drawable(StringBuffer& buf_) : buf(buf_) {}
  StringBuffer& applyStyle(const LineStyle& s) {
    buf.append(s.lineWidth).append(' ').append(s.linecolor).append(' ').append(s.dashstyle).append(" setlinestyle\n");
  }
  StringBuffer& applyStyle(const TextStyle& s) {
    return buf.append("%applyTextStyle\n").append(s.color).append(" setrgbcolor /").append(s.font).
      append(' ').append(s.size).append(" selectFont\n");
  }
  StringBuffer& applyStyle(const FillStyle& s) {
    return buf.append(s.color).append(" setrgbcolor\n");
  }

  void fillRect(double x, double y, double x2, double y2) {
    buf.append(x, ' ', y, ' ', x2, ' ', y2).append(" fillRect\n");
  }

  void fillRect(const FillStyle& s, double x, double y, double x2, double y2) {
    applyStyle(s).append(' '); // set background color of box
    fillRect(x, y, x2, y2);
  }

  void drawRect(double x, double y, double w, double h) {
    buf.append(x, ' ', y, ' ', w, ' ', h).append(" drawRect\n");
  }

  void drawRect(const LineStyle& s, double x, double y, double w, double h) {
    applyStyle(s).append(' '); // set background color of box
    drawRect(x, y, w, h);
  }

  void drawRoundRect(double x, double y, double w, double h, double r) {
    buf.append(x, ' ', y, ' ', w, ' ', h).append(' ').append(r).append(" drawRoundRect\n");
  }

  void drawRoundRect(const LineStyle& s, double x, double y, double w, double h, double r) {
    applyStyle(s).append(' '); // set background color of box
    drawRoundRect(x, y, w, h, r);
  }

  void fillRoundRect(double x, double y, double w, double h, double r) {
    buf.append(x, ' ', y, ' ', w, ' ', h).append(' ').append(r).append(" fillRoundRect\n");
  }

  void fillRoundRect(const FillStyle& s, double x, double y, double w, double h, double r) {
    applyStyle(s).append(' '); // set background color of box
    fillRoundRect(x, y, w, h, r);
  }

  void line(double x1, double y1, double x2, double y2) {
    buf.append(x1, ' ', y1).append(" moveto ").append(x2, ' ', y2).append(" lineto stroke\n");
  }

  void line(LineStyle& style, double x1, double y1, double x2, double y2) {
    applyStyle(style);
    line(x1, y1, x2, y2);
  }

  void drawPolyline(double x[], double y[], int n) {
    displayArray(x, n);
    displayArray(y, n);
    buf.append(" polyline\n");
  }

  void drawPolyline(LineStyle& s, double x[], double y[], int n) {
    applyStyle(s);
    drawPolyline( x, y, n);
  }

  void drawPolygon(double x[], double y[], int n) {
    for (int i = 0; i < n; i++) {
      buf.append(x[i], ' ', y[i]).append(' ');
    }
    buf.append(n);
    buf.append(" drawpolygon\n");
  }

  void drawSegments(double x[], double y[], int n, int offset) {
    for (int i = 0; i < n; i++) {
      buf.append(x[i], ' ', y[i], ' ', x[i+offset], ' ', y[i+offset]).append(' ');
    }
    buf.append(n);
    buf.append(" drawsegments\n");
  }

  void fillPolygon(double x[], double y[], int n) {
    for (int i = 0; i < n; i++) {
      buf.append(x[i], ' ', y[i]).append(' ');
    }
    buf.append(n);
    buf.append(" fillpolygon\n");
  }

  void fillPolygon(LineStyle& s, double x[], double y[], int n) {
    applyStyle(s);
    fillPolygon( x, y, n);
  }

  void drawGrid(double x0, double x1, int m, double y0, double y1, int n) {
    double x = x0, dx = (x1-x0)/(m-1);
    for (int i = 0; i < m; i++, x += dx) {
      line(x, y0, x, y1);
    }
    double y = y0, dy = (y1-y0)/(n-1);
    for (int i = 0; i < n; i++, y += dy) {
      line(x0, y, x1, y);
    }
  }

  void drawCircle(double x, double y, double r) {
    buf.append(x, ' ', y, ' ', r).append(" 0 360 arc stroke\n");
  }

  void fillCircle(double x, double y, double r) {
    buf.append(x, ' ', y, ' ', r).append(" 0 360 arc fill\n");
  }

  void translateRotateScalePlot(double x[], double y[], double rot[], double scale[], int n, const char iconName[]) {
    for (int i = 0; i < n; i++) {
      buf.append(scale[i], ' ', rot[i], ' ', x[i], ' ', y[i]).append(' ');
    }
    buf.append(n).append(' ');
    buf.append(iconName).append(" translaterotatescaleplot\n");
  }

  void translateRotateScalePlot(FillStyle& s,
				double x[], double y[], double rot[], double scale[], int n, const char iconName[]) {
    applyStyle(s);
    translateRotateScalePlot(x, y, rot, scale, n, iconName);
  }

  void translateScalePlot(double x[], double y[], double scale[], int n, const char iconName[]) {
    for (int i = 0; i < n; i++) {
      buf.append(scale[i], ' ', x[i], ' ', y[i]).append(' ');
    }
    buf.append(n).append(' ');
    buf.append(iconName).append(" translatescaleplot\n");
  }

  void translateScalePlot(FillStyle& s, double x[], double y[], double scale[], int n, const char iconName[]) {
    applyStyle(s);
    translateScalePlot(x, y, scale, n, iconName);
  }

  void translateScalePlot(double x[], double y[], double scale, int n, const char iconName[]) {
    displayArray(x, n);
    displayArray(y, n);
    buf.append(scale).append(' ');
    buf.append(iconName).append(" markerplot\n");
  }

  void translateScalePlot(FillStyle& s, double x[], double y[], double scale, int n, const char iconName[]) {
    applyStyle(s);
    translateScalePlot(x, y, scale, n, iconName);
  }

  void vectorPlot(FillStyle& fillStyle, double x[], double y[], double rot[], int n, double scale, const char arrowName[]) {
    applyStyle(fillStyle);
    displayArray(x, n);
    displayArray(y, n);
    displayArray(rot, n);
    buf.append(' ').append(scale).append(' ').append(arrowName).append(" vectorplot\n");
  }

#if 0
  void translateRotatePlot(double x[], double y[], double rot[], int n, const char iconName[]) {
    for (int i = 0; i < n; i++) {
      buf.append(scale[i], ' ', x[i], ' ', y[i]).append(' ');
    }
    buf.append(n).append(' ');
    buf.append(iconName).append(" translaterotplot\n");
  }

  void translateRotatePlot(FillStyle& s, double x[], double y[], double rot[], int n, const char iconName[]) {
    applyStyle(s);
    translateRotatePlot(x, y, rot, n, iconName);
  }
#endif

  void text(double x, double y, const char t[]) {
    buf.append(x, ' ', y).append(" moveto (").append(t).append(") show\n");
  }

  void text(double x, double y, double r, const char t[]) {
    buf.append(x, ' ', y).append(" moveto gsave ").append(r).append("rotate (").append(t).append(") show grestore\n");
  }

  void text(const TextStyle& s, double x, double y, const char t[]) {
    applyStyle(s).append(' ');
    text(x, y, t);
  }

  void text(const TextStyle& s, double x, double y, double r, const char t[]) {
    applyStyle(s).append(' ');
    text(x, y, r, t);
  }

  void drawTicksX(double x0, double x1, int numTicks1, double y0, double size1) {
    buf.append(x0, ' ', x1, ' ', numTicks1).append(' ').append(y0, ' ', y0+size1).append(" xticks\n");
  }

  void drawTicksY(double y0, double y1, int numTicks1, double x0, double size1) {
    buf.append(y0, ' ', y1, ' ', numTicks1).append(' ').append(x0, ' ', x0+size1).append(" yticks\n");
  }

  void drawTicksX(double x0, double x1, int numTicks1, double y0, double size1, int numTicks2, double size2) {
    buf.append(x0, ' ', x1, ' ', numTicks1).append(' ').append(y0, ' ', y0+size1).append(" xticks\n");
    buf.append(x0, ' ', x1, ' ', numTicks2).append(' ').append(y0, ' ', y0+size2).append(" xticks\n");
  }

  void drawTicksY(double y0, double y1, int numTicks1, double x0, double size1, int numTicks2, double size2) {
    buf.append(y0, ' ', y1, ' ', numTicks1).append(' ').append(x0, ' ', x0+size1).append(" yticks\n");
    buf.append(y0, ' ', y1, ' ', numTicks2).append(' ').append(x0, ' ', x0+size2).append(" yticks\n");
  }

  virtual void draw() = 0;
};

class Component : public Drawable {
protected:
  double x, y, width, height; 
public:
  Component(Document& doc) : Drawable(doc.getBuffer()) {
    // TODO: Configure anything drawable here, at the moment, nothing to do.
    // Perhaps all generic decoration type stuff, borders, etc belongs here.
     doc.computeBounds(*this);
  }
  void setBounds(double x_, double y_, double width_, double height_) {
    x = x_; y = y_; width = width_; height = height_;    
  }

  friend class Document;
};

// A container is a special component that contains a list of components.
// Drawing the container means drawing all its contents
class Container : public Component {
private:
  GrowArray<Drawable*> drawlist;
public:
  Container(Document& doc) : Component(doc) {}
  void add(Drawable& d) {
    drawlist.add(&d);
  }
  void draw() {
    for (int i = 0; i < drawlist.size(); i++) {
      drawlist[i]->draw();
    }
  }
};

// optimized class for 3d transformations
// Note that I only use 12 values, not 16 since 4 are unused
class Matrix4 {
private:
  double m[12]; // only those elements necessary for 3d graphics, 4x3 matrix
public:
  Matrix4() { ident(); }
  Matrix4
  (
   double m0, double m1, double m2, double m3,
   double m4, double m5, double m6, double m7, 
  double m8, double m9, double m10, double m11
   ) {
    m[0] = m0; m[1] = m1; m[2] = m2; m[3] = m3;
    m[4] = m4; m[5] = m5; m[6] = m6; m[7] = m7;
    m[8] = m8; m[9] = m9; m[10] = m10; m[11] = m11;
  }
    
  void ident() {
    m[0] = 1;  m[1] = 0;  m[2] = 0;
    m[3] = 0;  m[4] = 1;  m[5] = 0;
    m[6] = 0;  m[7] = 0;  m[8] = 1;
    m[9] = 0; m[10] = 0; m[11] = 0;
  }
  friend ostream& operator <<(ostream& s, const Matrix4& m) {
    s << m.m[0] << '\t' <<  m.m[1] << '\t' <<  m.m[2]  << '\t' <<  m.m[3] << '\n';
    s << m.m[4] << '\t' <<  m.m[5] << '\t' <<  m.m[6]  << '\t' <<  m.m[7] << '\n';
    s << m.m[8] << '\t' <<  m.m[9] << '\t' <<  m.m[10] << '\t' <<  m.m[11] << '\n';
    return s;
  }
  Matrix4 operator *(const Matrix4& b) {
    Matrix4 ans;
    ans.m[0] = m[0]*b.m[0] + m[1]*b.m[4] + m[2]*b.m[8];
    ans.m[1] = m[0]*b.m[1] + m[1]*b.m[5] + m[2]*b.m[9];
    ans.m[2] = m[0]*b.m[2] + m[1]*b.m[6] + m[2]*b.m[10];
    ans.m[3] = m[0]*b.m[3] + m[1]*b.m[7] + m[2]*b.m[11] + m[3];

    ans.m[4] = m[4]*b.m[0] + m[5]*b.m[4] + m[6]*b.m[8];
    ans.m[5] = m[4]*b.m[1] + m[5]*b.m[5] + m[6]*b.m[9];
    ans.m[6] = m[4]*b.m[2] + m[5]*b.m[6] + m[6]*b.m[10];
    ans.m[7] = m[4]*b.m[3] + m[5]*b.m[7] + m[6]*b.m[11] + m[7];

    ans.m[8] =  m[8]*b.m[0] + m[9]*b.m[4] + m[10]*b.m[8];
    ans.m[9] =  m[8]*b.m[1] + m[9]*b.m[5] + m[10]*b.m[9];
    ans.m[10] = m[8]*b.m[2] + m[9]*b.m[6] + m[10]*b.m[10];
    ans.m[11] = m[8]*b.m[3] + m[9]*b.m[7] + m[10]*b.m[11] + m[11];
    return ans;
  }

  void transform(double& x, double& y, double& z) {
    double tempx = m[0] * x + m[1] * y + m[2] * z + m[3];
    double tempy = m[4] * x + m[5] * y + m[6] * z + m[7];
    z = m[8] * x + m[9] * y + m[10] * z + m[11];
    x = tempx;
    y = tempy;
  }

  void project2(double x, double y, double z, double& xout, double& yout) {
    xout = m[0] * x + m[1] * y + m[2] * z + m[3];
    yout = m[4] * x + m[5] * y + m[6] * z + m[7];
    //    cerr << "projected: " << xout << "," << yout << "\n";
  }

  static Matrix4 rotateX(double rad) {
    double c = cos(rad), s = sin(rad);
    return Matrix4
      (
       1,   0,   0,   0,
       0,   c,   s,   0,
       0,  -s,   c,   0
       );
  }
  static Matrix4 rotateZ(double rad) {
    double c = cos(rad), s = sin(rad);
    return Matrix4
      (
       c,   s,   0,   0,
      -s,   c,   0,   0,
       0,   0,   1,   0
       );
  }

  static Matrix4 rotateY(double rad) {
    double c = cos(rad), s = sin(rad);
    return Matrix4
      (
       c,   0,   s,   0,
       0,   1,   0,   0,
      -s,   0,   c,   0
       );
  }

  static Matrix4 scale(double sx, double sy, double sz) {
    return Matrix4
      (
       sx,   0,   0,   0,
       0,   sy,   0,   0,
       0,    0,  sz,   0
       );
  }

  static Matrix4 translate(double dx, double dy, double dz) {
    return Matrix4
      (
       0,   0,   0,   dx,
       0,   0,   0,   dy,
       0,   0,   0,   dz
       );
  }

  void trans(double x, double y, double z) {
    m[3] += x; m[7] += y; m[11] += z;
  }
#if 0
  void rotX(double rad) {  }
  void rotY(double rad) {  }
  void rotZ(double rad) {  }
  // and scale, and translate...
#endif
};

// Since postscript doesn't do 3d, do all the rotations on the computer, then just draw the projected stuff
class Component3D : public Component {
private:
  Matrix4 xform;
public:
  Component3D(Document& doc, const Matrix4& xform_) : Component(doc), xform(xform_) {}

  void line(double x0, double y0, double z0, double x1, double y1, double z1) {
    double xs0, ys0, xs1, ys1;
    xform.project2(x0, y0, z0, xs0, ys0);
    xform.project2(x1, y1, z1, xs1, ys1);
    Component::line(xs0, ys0, xs1, ys1);
  }

  void box(double x0, double y0, double z0, double x1, double y1, double z1) {
    double x[8],y[8];

    xform.project2(x0, y0, z0, x[0], y[0]);
    xform.project2(x1, y0, z0, x[1], y[1]);
    xform.project2(x1, y1, z0, x[2], y[2]);
    xform.project2(x0, y1, z0, x[3], y[3]);
    drawPolygon(x, y, 4);
    //    drawQuad(xs[0], ys[0], x[1], y[1], x[2], y[2], x[3], y[3]);
    xform.project2(x0, y0, z1, x[4], y[4]);
    xform.project2(x1, y0, z1, x[5], y[5]);
    xform.project2(x1, y1, z1, x[6], y[6]);
    xform.project2(x0, y1, z1, x[7], y[7]);
    drawPolygon(x+4, y+4, 4);
    drawSegments(x, y, 4, 4);
  }
};

// Represent the scale information for a 2d graph, with x and y scale.
// Each may be any of the scales (right now linear, log, eventually schematic).
// Since I used a reference below, once you construct this, it cannot change
// Perhaps I should have used a pointer, so you could dynamically change the x scale,
// but at least the current convention is, you create the graph, you create a ScaleInfo for it,
// and then if you want another graph, do it again. That's not so terrible
class ScaleInfo {
public:
  Scale& xScale;
  Scale& yScale;
  double xmin, xmax, ystart, yend;

  ScaleInfo(istream& s, double width, double height, const ComponentLayout& layout) throw(char*) :
    xScale(Scale::readScale(s, "xscale", layout.leftMargin, width-layout.leftMargin-layout.rightMargin)),
    yScale(Scale::readScale(s, "yscale", layout.botMargin, height-layout.botMargin-layout.topMargin)) {
    xmin = expectDouble(s, "xmin");
    xmax = expectDouble(s, "xmax");
    ystart = expectDouble(s, "ystart");
    yend = expectDouble(s, "yend");
  }

  // set the inset bounds within the rectangle allocated by the page layout and change the scaleinfo accordingly
  void setBounds(double x, double y, double width, double height) {
    xScale.setBounds(xmin, xmax, x, width);
    yScale.setBounds(ystart, yend, y, height);
  }

  void scale(double x, double y, double& xout, double& yout) {
    xout = xScale.scale(x);
    yout = yScale.scale(y);
  }
  bool inRange(double x, double y) {
    return xScale.inRange(x) && yScale.inRange(y);
  }
#if 0
  ScaleInfo(double xmin_, double xmax_, double ymin_, double ymax_,
	    double pX0, double pY0, double width, double ) :
    xScale(xScale_), yScale(yScale_) {
    xmin = expectDouble(s, "xmin");
    xmax = expectDouble(s, "xmax");
    ystart = expectDouble(s, "ystart");
    yend = expectDouble(s, "yend");
  }
#endif  
};

// A graph component, multiple Datasets, and scales for x-y
class Graph2D : public Component {
private:
#if 0
  // TODO: Add standard pool of line styles for default
    static LineStyle lineStyles[];
    static FillStyle markerStyles[];
#endif

  // Base class for what you draw on a graph scaled
  struct Dataset : Drawable {
  public:
    string name;
    Dataset(StringBuffer& buf, const char name_[]) : Drawable(buf), name(name_) {}
  };

  // a single line, connect the dots
  struct DataLine : public Dataset {
    GrowArray<double> x;
    GrowArray<double> y;
    LineStyle lineStyle;
  public:
    DataLine(StringBuffer& buf, double x_[], double y_[], int n, const char name[], Scale& xScale, Scale& yScale, const LineStyle& lineStyle_) :
      Dataset(buf, name),
      x(x_, n), y(y_, n), lineStyle(lineStyle_) {
      xScale.scale(&x[0], n);
      yScale.scale(&y[0], n);

    }

    DataLine(StringBuffer& buf, const vector<double>& x_, const vector<double> y_, const char name[], Scale& xScale, Scale& yScale, const LineStyle& lineStyle_) :
      Dataset(buf, name),
      x(x_.size()), y(y_.size()), lineStyle(lineStyle_) {
      int n = x_.size();
      // TODO: How do you forcibly ask for a size if you know it???
//      x.capacity(n);
 //     y.capacity(n);
      for (int i = 0; i < n; i++) {
	x.add(xScale.scale(x_[i]));
	y.add(yScale.scale(y_[i]));
	//x[i] = xScale.scale(x_[i]);
	//y[i] = yScale.scale(y_[i]);
      }
    }

    DataLine(StringBuffer& buf, const vector< vector<double> >& data, int xcol, int ycol, const char name[], Scale& xScale, Scale& yScale, const LineStyle& lineStyle_) :
      Dataset(buf, name),
      x(), y(), lineStyle(lineStyle_) {
      int n = data.size();
      // TODO: How do you forcibly ask for a size if you know it???
      x.size(n);
      y.size(n);
      for (int i = 0; i < n; i++) {
	x[i] = xScale.scale(data[i][xcol]);
	y[i] = yScale.scale(data[i][ycol]);
      }
    }

    void draw() {
      drawPolyline(&x[0], &y[0], x.size());
    }
  };

  // Draw at each point, the term marker is stolen from matlab
  struct Markers : public Dataset {
    GrowArray<double> x;
    GrowArray<double> y;
    string markerName;
    double scale;
    FillStyle markerStyle;
  public:
    Markers(StringBuffer& buf, double x_[], double y_[], int n, const char name[], const char markerName_[],
	    Scale& xScale, Scale& yScale,
	    double scale_, const FillStyle& markerStyle_) :
      Dataset(buf, name),
      x(x_, n), y(y_, n), markerName(markerName_), scale(scale_), markerStyle(markerStyle_) {
      xScale.scale(&x[0], n);
      yScale.scale(&y[0], n);
    }
    void draw() {
      Drawable::translateScalePlot(markerStyle, &x[0], &y[0], scale, x.size(), markerName.c_str());
    }
  };

  // both connected line and markers
  struct DataLineAndMarkers : public Dataset {
    GrowArray<double> x;
    GrowArray<double> y;
    LineStyle lineStyle;
    string markerName;
    double scale;
    FillStyle markerStyle;
  public:
    DataLineAndMarkers(StringBuffer& buf, double x_[], double y_[], int n, const char name[],
		       const char markerName_[], 
		       Scale& xScale, Scale& yScale,
		       double scale_,
		       const LineStyle& lineStyle_, const FillStyle& markerStyle_) :
      Dataset(buf, name),
      x(x_, n), y(y_, n), markerName(markerName_), scale(scale_), markerStyle(markerStyle_) {
      xScale.scale(&x[0], n);
      yScale.scale(&y[0], n);
    }
    void draw() {
      drawPolyline(&x[0], &y[0], x.size());
      translateScalePlot(markerStyle, &x[0], &y[0], scale, x.size(), markerName.c_str());
    }
  };

  // gorgeous arrows, perfectly sharp. Why can't the imbeciles at matlab do this, they've only had 10 years....
  struct Vectors : public Dataset {
    GrowArray<double> x;
    GrowArray<double> y;
    GrowArray<double> dir;
    GrowArray<double> mag;
    double arrowSize;
    string arrowName;
    FillStyle arrowStyle;
  public:
    Vectors(StringBuffer& buf, double x_[], double mag_[], double dir_[], int n, const char name[],
	    Scale& xScale, Scale& yScale, 
	    double arrowSize_, const char arrowName_[],
	    const FillStyle& arrowStyle_) :
      Dataset(buf, name),
      x(x_, n), y(mag_, n), dir(dir_, n), mag(mag_, n),
      arrowSize(arrowSize_), arrowName(arrowName_), arrowStyle(arrowStyle_) {
      xScale.scale(&x[0], n);
      yScale.scale(&y[0], n);
    }
    void draw() {
      //      translateRotatePlot(arrowStyle, &x[0], &y[0], &dir[0], x.size(), arrowName);
      vectorPlot(arrowStyle, &x[0], &y[0], &dir[0], x.size(), arrowSize, arrowName.c_str());
    }
  };

  const GraphStyle& style;
  // allow arbitrary scales for each axis. Currently supporting linear and logarithmic
  ScaleInfo scaling;
#if 0
  Scale& xScale;
  Scale& yScale;
  double xmin, xmax, ystart, yend;
#endif

  GrowArray<Dataset*> datasets;
public:
  Graph2D(Document& doc, GraphStyle& style_, ScaleInfo& scaling_, double x[], double y[], int numPoints,
	  const LineStyle& lineStyle, const FillStyle& markerStyle) : 
    Component(doc),
    style(style_),
    scaling(scaling_) {
    addDataLineAndMarkers(x, y, numPoints, "", "/diamond", 4, lineStyle, markerStyle);
    doc.add(*this);
  }

  Graph2D(Document& doc, GraphStyle& style_, ScaleInfo& scaling_) : 
    Component(doc),
    style(style_),
    scaling(scaling_) {
    scaling.setBounds(style.leftMargin, style.botMargin, width, height);
  }

  Graph2D(Document& doc, istream& s)  throw(char*) :
    Component(doc),
    style(s),
    scaling(s, width, height, style) {
  }
  
  Graph2D(Document& doc, GraphStyle& style_, istream& s)  throw(char*) :
    Component(doc),
    style(style_),
    scaling(s, width, height, style) {
  }

#if 0
    xScale(Scale::readScale(s,"xscale",  style.leftMargin, width-style.leftMargin-style.rightMargin)),
    yScale(Scale::readScale(s, "yscale", style.botMargin, height-style.botMargin-style.topMargin)) {
    xmin = expectDouble(s, "xmin");
    xmax = expectDouble(s, "xmax");
    ystart = expectDouble(s, "ystart");
    yend = expectDouble(s, "yend");

  }
#endif

  void horizontalLine(double y, const LineStyle& s) {
    applyStyle(s);
    y = scaling.yScale.scale(y);
    Component::line(style.leftMargin, y, width-style.rightMargin, y);
  }

  void verticalLine (double x, const LineStyle& s) {
    applyStyle(s);
    x = scaling.xScale.scale(x);
    Component::line(x, style.botMargin, x, height-style.topMargin);
  }
  
  void line(double x1, double y1, double x2, double y2, LineStyle& style) {
    scalePair(x1, y1);
    scalePair(x2, y2);
    Component::line(x1, y1, x2, y2);
  }

  void scalePair(double& x, double& y) {
    x = scaling.xScale.scale(x);
    y = scaling.yScale.scale(y);
  }

  StringBuffer& appendPair(double x, char sep, double y) {
    return buf.append(x).append(sep).append(y);
  }

  void markerplot(const LineStyle& style, 
		  const double x[], const double y[], int numPoints,
		  double scale, const char marker[]) {
    applyStyle(style);
    buf.appendBrackets("[", x, numPoints, ' ', "] ");
    buf.appendBrackets("[", y, numPoints, ' ', "] ");
    buf.append(scale).append(" /").append(marker).append(" markerplot\n");
  }

  void lineplot(const LineStyle& style, const double x[], const double y[], int numPoints, double scale) {
    applyStyle(style);
    buf.appendBrackets("[", x, numPoints, ' ', "] ");
    buf.appendBrackets("[", y, numPoints, ' ', "] ");
    buf.append(scale).append(" lineplot\n");
  }

#if 0
  //TODO: Check vectorPlot and then remove this one
  /*
    create a plot where x is the x coordinate, the magnitude is the y, 
    draw an arrow with rotation angle at that location, scaled in points
    arrow size is constant
  */
  void vectorplot(const double x[], const double mag[], int numPoints, const double angle[], double scale) {
    buf.appendBrackets("[", x, numPoints,  ' ', "] ");
    buf.appendBrackets("[", mag, numPoints, ' ', "] ");
    buf.appendBrackets("[", angle, numPoints, ' ', "] ");
    buf.append(scale).append("/a1 vectorplot\n");
  }
#endif

  void drawTicksX(double xMin, double xMax, int count, double y0, double y1, Scale& scale) {
    Component::drawTicksX(scale.scale(xMin), scale.scale(xMax), count, y0, y1);
  }

  void drawTicksY(double yMin, double yMax, int count, double x0, double x1, Scale& scale) {
    Component::drawTicksY(scale.scale(yMin), scale.scale(yMax), count, x0, x1);
  }

  void addDataLine(double x[], double y[], int n, const char name[], const LineStyle& lineStyle) {
    datasets.add(new DataLine(buf, x, y, n, name, scaling.xScale, scaling.yScale, lineStyle));
  }

  void addDataLine(const vector<double>& x, const vector<double>& y, const char name[], const LineStyle& lineStyle) {
    datasets.add(new DataLine(buf, x, y, name, scaling.xScale, scaling.yScale, lineStyle));
  }

  void addDataLine(const vector< vector<double> >& data, int xcol, int ycol, const char name[], const LineStyle& lineStyle) {
    datasets.add(new DataLine(buf, data, xcol, ycol, name, scaling.xScale, scaling.yScale, lineStyle));
  }


  void addMarkers(double x[], double y[], int n, const char name[], 
		  const char markerName[], double scale,  const FillStyle& fillStyle) {
    datasets.add(new Markers(buf, x, y, n, name, markerName, scaling.xScale, scaling.yScale, scale, fillStyle));
  }

  void addDataLineAndMarkers(double x[], double y[], int n, const char name[], 
			     const char markerName[], double scale,
			     const LineStyle& lineStyle, const FillStyle& fillStyle) {
    datasets.add(new DataLineAndMarkers(buf, x, y, n, name, markerName, scaling.xScale, scaling.yScale, scale, lineStyle, fillStyle));
  }

  void addVectors(double x[], double y[], double rot[], int n, const char name[], double arrowSize, const char arrowName[],
		  const FillStyle& fillStyle) {
    datasets.add(new Vectors(buf, x, y, rot, n, name, scaling.xScale, scaling.yScale, arrowSize, arrowName, fillStyle));    
  }

  void add(double x[], double y[], int n, const char name[]) {
    //    addDataLine(x, y, n,name, lineStyles[0]);
  }

  void draw() {
    buf.append("%graph2d\n");
    //TODO:    factor all generic rectangular stuff into Component::draw();
    applyStyle(style.bg); // set background color of box
    fillRect(0, 0, width, height);
    applyStyle(style.bg_graph); // set background color of box
    double innerWidth = width-style.rightMargin-style.leftMargin;
    double innerHeight = height-style.topMargin-style.botMargin;

    double rightEdge = width-style.rightMargin;
    double topEdge = height-style.topMargin;

    fillRect(style.leftMargin, style.botMargin, rightEdge, topEdge);

    if (style.box_border_style != NULL) {
      //TODO: Fix to work with margins
      drawRect(style.leftMargin, style.botMargin, width, height);
    }
    // calculate default tick size
    double tickSize = style.tickPercent * util::min(innerWidth, innerHeight);
    double xTickSize = tickSize, yTickSize = tickSize;
    double ymin, ymax;
    minmax(scaling.ystart, scaling.yend, ymin, ymax);

    // TODO: Fix this!
    int numXTicks = style.num_x_ticks;
    int numYTicks = style.num_y_ticks;
    double xinc = (scaling.xmax - scaling.xmin) / (numXTicks-1);
    double yinc = (ymax - ymin) / (numYTicks-1);

    applyStyle(style.tick_style);
    drawTicksX(scaling.xmin, scaling.xmax, numXTicks, style.botMargin+style.xtick_pos, yTickSize, scaling.xScale); // bottom edge
    drawTicksX(scaling.xmin, scaling.xmax, numXTicks, topEdge-style.xtick_pos, -yTickSize, scaling.xScale); // top edge
    applyStyle(style.tick_num_text_style);
    drawTickNumberX(scaling.xmin, xinc, style.num_x_ticks, style.xticknumdx, style.xticknumy, style.x_tick_num_format.c_str());
    double good_dens[] = {.1, .2, .25, .5, 1, 2, 2.5, 3, 4, 5, 10, 15, 20, 25, 30};

    //    niceNumbers(ymin, ymax, 15, style.inclusive_y_min, style.inclusive_y_max, good_dens, sizeof(good_dens)/sizeof(double), ymin, yinc, numYTicks);
    applyStyle(style.tick_style);
    drawTicksY(ymin, ymax, numYTicks, style.leftMargin+style.ytick_pos, yTickSize, scaling.yScale); // left edge
    drawTicksY(ymin, ymax, numYTicks, rightEdge-style.ytick_pos, -yTickSize, scaling.yScale); // right edge
    applyStyle(style.tick_num_text_style);
    drawTickNumberY(ymin, yinc, numYTicks, style.yticknumx, style.yticknumdy, style.y_tick_num_format.c_str());
    for (int i = 0; i < datasets.size(); i++) {
      datasets[i]->draw();
    }
  }

  void drawTickNumberX(double xmin, double xinc, int count, double dxpts, double ypts, const char fmt[]) {
    buf.append("[ ");
    for (int i = 0; i < count; i++) {
      // TODO: This is wrong, assumes linear scaling whichis not always true
      buf.appendFormatted(fmt, xmin + i * xinc); 
    }
    double xpts = scaling.xScale.scale(xmin); // same, see above
    float dx = float(scaling.xScale.scaleOffset(xinc));
    buf.append("]").append(dx).append(" 0 ").append(xpts + dxpts, ' ', ypts).append(" displayTextBlock \n");
  }

  void drawTickNumberY(double ymin, double yinc, int count, double xpts, double dypts, const char fmt[]) {
    buf.append(" [ ");
    for (int i = 0; i < count; i++) {
      buf.appendFormatted(fmt, ymin + i * yinc); // TODO: This is wrong (see above)
    }
    double ypts = scaling.yScale.scale(ymin); // TODO: This is wrong (see above)
    double dy = scaling.yScale.scaleOffset(yinc);
    buf.append("] 0 ").append(dy).append(' ').append(xpts, ' ', ypts + dypts).append(" displayTextBlock\n");
  }

  void niceNumbers(double& min, double &max, int max_ticks, bool inclusiveMin, bool inclusiveMax,
		   double good_denominators[], int good_den_size,
		   double& nice_min_out, double& den_out, int& count_out) {
    double range = max - min;
    for (int i = 0; i < good_den_size; i++) {
      double den = good_denominators[i];
      if (range / den <= max_ticks) {
	double nice_min = calc_ceil_or_floor(inclusiveMin, false, min/den) * den;
	double nice_max = calc_ceil_or_floor(inclusiveMax, true, max/den) * den;
	if ((nice_max - nice_min) / den > max_ticks && i < good_den_size - 1) {
	  den = good_denominators[i+1];
	  nice_min = calc_ceil_or_floor(inclusiveMin, false, min/den) * den;
	  nice_max = calc_ceil_or_floor(inclusiveMax, true, max/den) * den;
	}

	count_out = int(ceil((nice_max - nice_min) / den))+1;
	nice_min_out = nice_min;
	den_out = den;
	break;
      }
    }
  }

  double  calc_ceil_or_floor(bool inc, bool max,  double val) {
    return (inc ^ max) ? floor(val) : ceil(val);
  }
};

// specialized plot, for a coastline
// breaking at each nan
// TODO: This REALLY should use high speed streams, since maps can get HUGE.
class Map : public Component {
private:
  vector<double> x;
  vector<double> y;
  vector<int> indexes;
  ScaleInfo scaling;
public:
  Map(Document& doc, ScaleInfo& scaling_, const char mapFile[]) : Component(doc), scaling(scaling_) {
    ifstream map(mapFile);
    enum {BUFSIZE=16384};
    char buf[BUFSIZE];
    int pos = 0;
    int lineCount = 0;
    while (!map.eof()) {
      lineCount++;
      map.getline(buf, BUFSIZE);
      if (buf[0] == 'n') {
	indexes.push_back(pos);
      } else {
	char* p;
	char* q;
	double xv = strtod(buf, &p);
	double yv = strtod(p, &q);
	if (p == buf || q == p) {
	  cerr << "error reading " << mapFile << " at line " << lineCount;
	  break;
	}

	x.push_back(xv);
	y.push_back(yv);
	pos++;
      }
    }
  }
  void add(double x[], double y[], double v[], int n) {
  }

  void draw() {
    int pos0 = indexes[0];
    int pos1;
    double xout, yout;
    buf.append('[');
    vector<float> px, py;
    for (int i = 1; i < indexes.size(); i++) {
      pos1 = indexes[i];
      bool lastNotInRange = false;
      px.clear();
      py.clear();
      for (int j = pos0; j < pos1; j++) {
	if (scaling.inRange(x[j], y[j])) {
	  scaling.scale(x[j], y[j], xout, yout);
	  px.push_back(float(xout));
	  py.push_back(float(yout));
	} else {
	  if (lastNotInRange)
	    continue;
	  else
	    lastNotInRange = true;
	}
      }
      if (px.size() > 1) {
	buf.append('[');
	for (int i = 0; i < px.size(); i++) {
	  buf.appendFormatted("%.2lf ", px[i], py[i]);
	}
	buf.append("]\n");
      }
      pos0 = pos1;
    }
    buf.append("] drawcoastline\n");
  }
};
#endif
