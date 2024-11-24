#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double x1 = (-b - sqrt(discriminant)) / (2 * a);
        double x2 = (-b + sqrt(discriminant)) / (2 * a);
        if (x1 > x2) swap(x1, x2);
        cout << fixed << setprecision(5) << "x1=" << x1 << ";x2=" << x2 << endl;
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        cout << fixed << setprecision(5) << "x1=x2=" << x << endl;
    } else {
        cout << "No answer!" << endl;
    }

    return 0;
}
