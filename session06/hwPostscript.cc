
int main() {
	Postscript p("out.ps");
	p.rect(0,0, 100,100);
	p.fill(255,0,0); // set color to bright red
	p.fillRect(0,0, 100,100);
	p.fill(0x0000FF); // take color as a single int (blue)
	p.fillCircle(300,400,150);
	p.stroke(255,255,0);
	p.line(0,0, 300,300);
	p.viewPort(0,300,300,500); // define absolute portion of the page to write to
	p.scale(0, PI, -1,+1); // define scale within the area
	p.plot(sin, 0, 2*PI, 1200);
	p.viewport(); // viewport is reset to the entire page
	p.grid(400,50, 400, 600,50, 600);
}
