#include <iostream>
using namespace std;

int a[100];

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 0; i--)  // 数据储存
        cin >> a[i]; 
    
    // 特判
    if (n == 0) {
        cout << a[n];
        return 0;
    }

    int i = n;
    // 对最高幂特殊处理
    if (a[i] == 0) {
        ;
    } else if (a[i] == -1) {
        cout << "-x^" << i;
    } else if (a[i] == 1) {
        cout << "x^" << i;
    } else {
        cout << a[i] << "x^" << i;
    }

    // 对n-1次幂 ~ 2次幂的处理
    for (i = n - 1; i >= 2; i--) {
        if (a[i] == 0) {
            ;
        } else if (a[i] == -1) {
            cout << "-x^" << i;
        } else if (a[i] == 1) {
            cout << "+x^" << i;
        } else if (a[i] > 0) {
            cout << "+" << a[i] << "x^" << i;
        } else {
            cout << a[i] << "x^" << i;
        }
    }

    // 对1次幂的处理
    i = 1;
    if (a[i] == 0) {
        ;
    } else if (a[i] == -1) {
        cout << "-x";
    } else if (a[i] == 1) {
        cout << "+x";
    } else if (a[i] > 0) {
        cout << "+" << a[i] << "x";
    } else {
        cout << a[i] << "x";
    }

    // 对0次幂的处理
    i = 0;
    if (a[i] != 0) {
        if (a[i] > 0) cout << "+";
        cout << a[i]; // 0和负数的逻辑一同处理
    }

    return 0;
}
