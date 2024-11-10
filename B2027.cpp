#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14;

int main() {
    double r;
    cin >> r;
    printf("%.5lf", 4.0 / 3 * PI * r * r * r);
    return 0;
}