#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // Find the maximum of the three numbers
    int maxNum;
    if (a >= b && a >= c) {
        maxNum = a;
    } else if (b >= a && b >= c) {
        maxNum = b;
    } else {
        maxNum = c;
    }

    cout << maxNum << endl;

    return 0;
}
