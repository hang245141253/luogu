#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double a = x1 - x2;
    double b = y1 - y2;
    printf("%.3lf", sqrt(a * a + b * b));
    return 0;
}