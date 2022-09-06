#include "Graph2D.hh"
#include <time.h>

void Document::dateNow() {
  struct tm gm;
  time_t now;
  time(&now);
  gmtime_r(&now, &gm);
  char buffer[256];
  sprintf(buffer, "%4d/%02d/%02d %02d:%02d:%02d",
	  gm.tm_year+1900, gm.tm_mday, gm.tm_mon+1, gm.tm_hour, gm.tm_min, gm.tm_sec);
  buf.append(buffer);
}

void Document::computeBounds(Component& c) {
    if (layout.boxCount >= layout.numCols * layout.numRows) {
      layout.boxCount = 0;
      endPage();
    }
    double x = layout.leftEdge, y = layout.topEdge;
    int row = layout.boxCount / layout.numCols;
    int col = layout.boxCount % layout.numCols;
    for (int i = 0; i < col; i++)
      x += layout.colSizes[i];
    for (int i = 0; i < row; i++)
      y -= layout.rowSizes[i];
    double width = layout.colSizes[col];
    double height = layout.rowSizes[row];
    c.setBounds(x, y-height, width, height);
    buf.append("gsave ").append(c.x).append(' ').append(c.y).append(" translate\n");
}

void Document::add(Component& c) {
  //c.draw();
    buf.append(" grestore\n");
    layout.boxCount++;
}

Scale& Scale::readScale(istream& s, const char name[], double pMin, double pSize) throw(char*) {
  string type;
  type = expectString(s, name);
  if (type == "linear") {
    double vMin, vMax;
    vMin = expectDouble(s, "minval");
    vMax = expectDouble(s, "maxval");
    return *new LinearScale(vMin, vMax, pMin, pSize);
  } else if (type == "log") {
    double vMin, vMax;
    vMin = expectDouble(s, "minval");
    vMax = expectDouble(s, "maxval");
    return *new LogScale(vMin, vMax, pMin, pSize);
  } else if (type == "schematic") {
    throw "unimplemented";
  } else
    throw "unimplemented";
}

void Document::includeEPS(string epsfile, double x, double y) {
  buf.append(x).append(' ').append(y).append(" translate\n").
    append("gsave\n").
    append("5 dict begin\n").
    append("/showpage {} def\n").
    append("/setpagedevice /pop load def\n").
    append("exch\n");
}
#if 0
LineStyle Graph2D::lineStyles[] = {
  
};

FillStyle markerStyles[] = {
};
#endif

