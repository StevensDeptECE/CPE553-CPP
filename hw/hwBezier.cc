#include "Bezier.hh"

int main() {
	/*
		Create a third order Bezier starting at location (0,0), ending in (200,0)
		with the derivative at each end controlled by the two middle points

		https://en.wikipedia.org/wiki/B%C3%A9zier_curve
		Bezier Curves are usually written in terms of their four control points
		B(t) = (1-t)^3P0 + 3(1-t)^2 P1 + 3(1-t)t^2 P2 + t^3 P3

		this can be more efficiently precomputed as:
		(1 - t)(1-t)(1-t) = (1-2t+t^2)(1-t) = 1 - 2t + t^2 - t + 2t^2 - t^3
		                  = (1 - 3t + 3t^2 - t^3) P0
		3(1-t)(1-t) = 3(1-2t+t^2) = (3 - 6t+3t^2) P1
		3(1-t)t^2 = 3(t^2 - t^3) P2
		t^3 P3


//TODO: THis is dodgy
		(X3 - 3X2 - X0) t^3
		(3X2 - 3X1 + 3X0) t^2
		(3X0 - 6X1) t
		(X0 + 3X1)


		Each segment requires 4 double precision numbers for each variable.
		x(t) = at^3 + bt^2 + ct + d
		y(t) = et^3 + ft^2 + gt + h

		Both problems are identical, let's just solve x(t)
		@t = 0, the first three terms are 0, so x(0) = d = X0 = 0 in this case
		@t = 1, x(t) = a + b + c + d = X1
		we know d from before, so: a + b + c = X1 - X0
		taking derivative: x'(t) = 3at^2 + 2bt + c
		@t = 0, c = 
	 */
	const double
		X0 = 0, Y0 = 0,
		X1 = 10, Y1 = 50,
		X2 = 190, Y2 = 50,
		X3 = 200, Y3 = 0;
	CubicBezier b(X0,Y0, X1,Y1, X2,Y2, X1,Y1);

	/*
		Now add a segment that starts where the other point ends, ending at (400,0)

	 */
	b.addSegment(10, 10, 390,-30, 400,0);

	ofstream f("bezierpts.dat");
	/*
		write out a sequence of the points along this bezier
		with the parameter t varying from 0 to 0.9 in each segment stepping by 0.1
		Since each segment starts with the same point the previous segment ends,
		you should not go until 1.0 except in the last segment
	*/
	b.write(f, 0.1);
}
