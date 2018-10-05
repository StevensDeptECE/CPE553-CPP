class Postscript {
public:
  
};

int main() {
  Postscript p("test.ps");
  p.line(0,0, 300,400);  // 0 0 moveto 300 400 lineto stroke
  int r = 255, g = 0, b = 0;
  p.setColor(r, g, b); // r, g, b should be from 0.0 to 1.0
	// should turn into 1 0 0 setrgbcolor\n
	
  p.drawRect(x, y, w, h);   // x y moveto x+w y lineto x+w y+h lineto ... closepath stroke 
  p.fillRect(x, y, w, h);   // x y moveto x+w y lineto x+w y+h lineto ... closepath fill 
  p.drawTriangle(x1,y1, x2,y2, x3,y3);
  p.fillTriangle(x1,y1, x2,y2, x3,y3);
  p.drawCircle(x,y,r); // x y 0 360 r arc stroke
	p.fillCircle(x, y, r);
	p.setFont("Helvetica", 32); //  "/Helvetica findfont 32 scalefont setfont"
  p.text(300,400, "testing testing 123"); // 300 400 moveto (testing testing 123)show

  p.grid(300, 50, 500, 400, 50, 700); // x = 300 to 500 stepping 50
	// y = 400 to 700 stepping 50

}
  


}
