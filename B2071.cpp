#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    for (int x = 2; x <= a && x <= b && x <= c; x++)
        if (a % x == b % x && b % x == c % x) {
            cout << x << endl;
            break;
        }
    return 0;
}