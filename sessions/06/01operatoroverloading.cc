#include <iostream>
#include <cmath>
using namespace std;
int this_is_snake_case; // c++ standard

class vec3d{
private:
    double x, y, z;
public:
    vec3d(double x, double y, double z):x(x), y(y), z(z){};
#if 0
    friend vec3d operator +(const vec3d a, const vec3d b) {
        return vec3d(a.x+b.x, a.y+b.y, a.z+b.z);
    }
    friend vec3d operator -(const vec3d a, const vec3d b) {
        return vec3d(a.x-b.x, a.y-b.y, a.z-b.z);
    }
    friend vec3d operator *(vec3d v1, double  s){
        return vec3d(v1.x*s, v1.y*s, v1.z*s);
    }
    friend vec3d operator *(double s, vec3d v1){
        return v1 * s;
    }
#endif
    friend vec3d operator -(const vec3d& v){
        return vec3d(-v.x, -v.y, -v.z);
    }
    friend double abs(vec3d v) {
        return sqrt( (v.x*v.x) + (v.y*v.y) + (v.z*v.z) );
    }
    vec3d operator +(const vec3d& b) const {
        return vec3d(x+b.x, y+b.y, z+b.z);
    }
    vec3d operator -(const vec3d& b) const {
        return vec3d(x-b.x, y-b.y, z-b.z);
    }
    vec3d operator *(double  s) const{
        return vec3d(x*s, y*s, z*s);
    }

    vec3d operator -() const {
        return vec3d(-x, -y, -z);
    }
    double abs() const {
        return sqrt( (x*x) + (y*y) + (z*z) );
    }

};




int main() {
    const vec3d v1(1.2,2.3,3.4);
    const vec3d v2(2.2,-2.3,1.2);
    // these 4 lines will work with either friend or member function syntax
    vec3d v3 = v1 + v2;
    vec3d v4 = v1 - v2;
    vec3d v4b = -v1;
    vec3d v5 = v1 * 1.5; // scalar multiplication

//  these requires friend
    double mag = abs(v5); // friend function
    vec3d v99 = 1.5 * v1;
    cout << v5;

    double mag2 = v5.abs();
}