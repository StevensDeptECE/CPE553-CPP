

int main() {
	// FIRST PART (ADD COLORS HERE)
	constexpr uint32_t BLACK = 0xFF000000; // black opaque
	constexpr uint32_t RED =   0xFF0000FF; // red opaque


	
	// SECOND PART (DO NOT EDIT)
	int xcenter = 100;
	int ycenter = 100;
	int xdiameter = 200;
	int ydiameter = 100;

	Bitmap b(BLACK); // Hardcoded size (600 x 400 pixels)
	
        b.horizLine(0, 500, 200, RED); // Red horizontal line, from x=0 to x=500, at y = 200
	b.vertLine(0, 399, 300, RED); // Red vertical line, from y=0 to y=399, at x = 300
	
	b.drawRect(200,200, 100,50, BLUE); // Blue rectangle, TOP-LEFT at x=200, y=200. width=100, height=50
	b.fillRect(201,201, 98,48, WHITE); // White rectangle, same rules as above, but filled with color
	
	b.line(400,0, 550,300, YELLOW); // Line drawn using https://en.wikipedia.org/wiki/Bresenham's_line_algorithm
	
	b.ellipse(xcenter, ycenter, xdiameter, ydiameter); //Ellipse using specs from above
	
	b.save("bitmap.png");
	
	
	// THIRD PART - OPTIONAL FUNCTION
	// 100pt bonus for properly implementing Wu's antialiasing
	//https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
	//b.antialiasedLine(400,0, 550,300, YELLOW);        
}

