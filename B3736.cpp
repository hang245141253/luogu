#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    // 辗转相除法
    int a, b;
    a = x, b = y;
    while (b != 0) {
        int mod = a % b;
        a = b;
        b = mod;
    }
    b = a, a = z;
    while (b != 0) {
        int mod = a % b;
        a = b;
        b = mod;
    }
    cout << a << endl;

    return 0;
}