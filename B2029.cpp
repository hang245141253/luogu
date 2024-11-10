#include <iostream>
using namespace std;

/**
 * 1 dm^3 = 1 L
 * 1000 cm^3 = 1 L
 * V = π * r^2 * h
*/

const double PI = 3.14;

int main() {
    int h, r;
    cin >> h >> r;
    cout << int(20 * 1000 / (PI * r * r * h) + 1);
    // +1向上取整
    return 0;
}