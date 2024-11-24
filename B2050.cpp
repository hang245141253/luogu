#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Check if the three sides can form a triangle
    if (a + b > c && a + c > b && b + c > a) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
