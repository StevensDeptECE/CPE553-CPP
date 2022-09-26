#include <cstdio>
#include <cstring>

using namespace std;
struct Person {
    char firstName[10];
    char lastName[10];
    int age;
};
int main() {
    Person p;
    p.age = 14;
    strcpy(p.firstName, "Rajashekhara");
    strcpy(p.lastName, "Chinnaswamy");
    printf("%s %s %d", p.firstName, p.lastName, p.age);
}