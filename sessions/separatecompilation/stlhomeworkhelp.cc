class Shape {
public:
	/*
		   
    p4     p3


		p1     p2

     facet(p1,p2,p3)
     facet(p1,p3,p4)

	 */

	// facet has 9 parameters
	void facet(ostream& s, double x1, double y1, double z2 ) {
		// compute the normal
		// https://stackoverflow.com/questions/19350792/calculate-normal-of-a-single-triangle-in-3d-space
	}

	void rect(ostream& s, double x1, double y1, double x1, .... ) {
		facet( );
		facet( );
	}
};

class Cube : pulic Shape {
private:
	double side;
public
	void print(ostream& s) {
	rect(s, );
		rect();
			rect();
				rect();
					rect();
						rect();
   }
	
}
class Cylinder : public Shape {

public:
	void print(ostream& s) {
		for (each side) {
			x, y, lastx, lasty
				z = 0, z=h
				rect(s, .....);
			float t = 0;
			float lastx = r, lasty = 0;
			for (int i = 0; i <= n; i++, t += PI*2/n) {
				float x = r * cos(t);
				float y = r * sin(t);
				rect(s, your 4 points go here!)
					//(x,y, lastx, lasty);
				  // z = 0  , z = H
					}  
    lastx = x; lasty = y;
  }

	void rect(ostream& s, double x1, double y1, double x1, .... ) {
		facet( );
		facet( );

	}
};
