#include <iostream>
using namespace std;

int main() {
    double x, a, y, b;
    cin >> x >> a >> y >> b;
    printf("%.2lf\n", (x * a - y * b) / (a - b));
    return 0;
}