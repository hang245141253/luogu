#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
    int n, i = 0;
    cin >> n;
    for (int i = n; i >= 0; i--) cin >> a[i];  // 数据储存
    // 特判
    if (n == 0) {
        cout << a[n];
        return 0;
    }
    // 对最高幂特殊处理
    i = n;
    if (a[i] != 0) {
        if (a[i] == -1)
            cout << "-x^" << i;
        else if (a[i] == 1)
            cout << "x^" << i;
        else if (a[i] > 1)
            cout << a[i] << "x^" << i;
        else if (a[i] < 1)
            cout << a[i] << "x^" << i;
    }
    // 对n-1次幂~2次幂的处理
    for (i = n - 1; i >= 2; i--) {
        if (a[i] != 0) {
            if (a[i] == -1)
                cout << "-x^" << i;
            else if (a[i] == 1)
                cout << "+x^" << i;
            else if (a[i] > 1)
                cout << "+" << a[i] << "x^" << i;
            else if (a[i] < 1)
                cout << a[i] << "x^" << i;
        }
    }
    // 对1次幂的处理
    i = 1;
    if (a[i] != 0) {
        if (a[i] == -1)
            cout << "-x";
        else if (a[i] == 1)
            cout << "+x";
        else if (a[i] > 1)
            cout << "+" << a[i] << "x";
        else if (a[i] < -1)
            cout << a[i] << "x";
    }
    // 对0次幂的处理
    i = 0;
    if (a[i] != 0) {
        if (n == 0) {
            if (a[i] != 0)
                cout << a[i];
        } else {
            if (a[i] > 0)
                cout << "+";
            cout << a[i];
        }
    }
    return 0;
}