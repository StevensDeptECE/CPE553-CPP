#include <iostream>
#include <cmath>
class Body {
    private:
    
    double Gm; // precompute G * mass for faster simulation
}
double gravForce(const double G, double m1, double m2, double x1, double y1, double z1, double x2, double y2, double z2){
    double dx = x1-x2, dy = y1-y2, dz = z1-z2;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    return G*m1*m2/ (r*r);
}

double accGrav(const double G, double m2, double x1, double y1, double z1, double x2, double y2, double z2){
    double dx = x1-x2, dy = y1-y2, dz = z1-z2;
    double rsq = dx*dx + dy*dy + dz*dz;
    return G*m2/ rsq;
}


constexpr double G = 6.67408E-11;
int main() {
    const double massEarth = 5.972e24;
    double ex = 0, ey = 0, ez = 0;
    const double massMoon = 7.35e22; 
    double r = 3e8;
    double theta = 0;
    double mx = r*cos(theta), ey = r*sin(theta), ez = 0;

    double F = gravForce(G, massEarth, massMoon, ex,ey,ez, mx,my,mz);
    double aEarth = F / massEarth;
    double r = 1.61261;
    double x = 1, y = 2, z = 3;
    x /= r; y /= r; z /= r;

    //faster:

    double invR = 1/r;
    x *= invR; y *= invR; z *= invR; // compiler will not do this for you

}