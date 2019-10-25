int main() {
	constexpr uint32_t BLACK = 0xFF000000; // black opaque
	constexpr uint32_t RED =   0xFF0000FF; // red opaque

	//hardcoded size 600 x 400
	Bitmap b(BLACK);
  b.horizLine(0, 500, 200, RED); // horizontal line from x=0 to x=500, @y = 200
	b.vertLine(0, 399, 300, RED); // y=0 to y=399 @ x= 300, red vertical line
	b.drawRect(200,200, 100,50, BLUE); // blue rectangle, top-left=200,200 w=100 h=50
	b.fillRect(201,201, 98,48, WHITE); // same but filled
	b.line(400,0, 550,300, YELLOW); // draw a line https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
	
	//optional, 100pt bonus for implementing Wu's antialiasing
	https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
	b.antialiedLine(400,0, 550,300, YELLOW);

	
  b.ellipse(xcenter, ycenter, xdiameter, ydiameter);
}

