

int main() {
    const vec3d a; // a.x = 0.0, a.y = 0.0, a.z = 0.0
    const vec3d b(1,2.5,3) // b.x = 1.0, b.y = 2.5, b.z = 3.0 DOUBLE!!!!
    double z = b.abs(); // magnitude of b (length of vector)
    const vec3d c = a + b; // use member
    const vec3d e = a - b; // use friend
    const vec3d f = -a;    // use member
    const vec3d g = +a;    // use friend

    double d1 = a.dot(b);
    double d2 = vec3d::dot(a,b);
    double d3 = dot(a,b); // friend
    // sorry, not supported! double d4 = a ⋅ b;
    cout << c << '\n';
    cout << e << '\n';
    cout << f << '\n';
    cout << g << '\n';
    cout << "d1=" << d1 << '\n';
    cout << "d2=" << d2 << '\n';
    cout << "d3=" << d3 << '\n';

}