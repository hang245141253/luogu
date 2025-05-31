#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool flag = false;
        double x = pow(n, 0.25);
        for (int i = 1; i <= x; i++) {
            if (i * i * i * i == n) {
                cout << i << endl;
                flag = true;
                break;
            }
        }
        if (!flag) cout << -1 << endl;
    }
    return 0;
}