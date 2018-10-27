int main() {
	const uint32_t BLACK = 0xFF000000;
	const uint32_t RED = 0xFFFF0000;
	const uint32_t GREEN = 0xFF00FF00;
	const uint32_t BLUE = 0xFF0000FF;
	const uint32_t YELLOW = 0xFFFFFF00;
	const uint32_t WHITE = 0xFFFFFFFF;
	
	Bitmap b(800,600, BLACK);
	b.line(0,0, 200,200, RED);
	b.line(0,0, 200,100, WHITE);
	b.rect(201,0, 100,100, BLUE);
	b.ellipse(301,0, 100,50, GREEN);
	b.fillEllipse(301,0, 80, 60, RED);
	b.fillRect(401,0,50,50, YELLOW);
	b.roundRect(0,150, 100,50, 10, RED);
	b.polygon(150,150, 50, 5, BLUE);
	b.fillPolygon(250,150, 50, 5, GREEN);
	b.bezier(300,150, 400,150, 500,250, 600,250, WHITE);
	b.bezier(600,250, 500,250, 400,200, 300,200, WHITE);
	b.line(300, 200, 300,150, GREEN);
	b.fill(350,200, YELLOW);
	b.triangle(300,300, 400,300, 350,400, BLUE);
	b.fillTriangle(310,310, 390,310, 350,390, GREEN);
	b.gouraudTriangle(400,300, RED, 500,300,GREEN, 450,400, BLUE);
	b.saveBMP("test.bmp");
	b.savePNG("test.png");
	Bitmap b2("earth.png"); // load the image from the file
	b2.copy(100, 100, 300, 200, b, 0,300); // copy the region from b2 into b at (x,y)
	
}
	
	
