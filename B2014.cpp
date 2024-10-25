#include <iostream>
using namespace std;

int main() {
    double r, PI = 3.14159;
    scanf("%lf", &r);
    double d = 2 * r;
    double c = 2 * r * PI;
    double s = PI * r * r;
    printf("%.4lf %.4lf %.4lf", d, c, s);
    return 0;
}