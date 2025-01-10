#include <iostream>
using namespace std;

void f1() {
    int n;
    cin >> n;

    while (n--) {
        int tmp;
        cin >> tmp;
        if (tmp == 1 || tmp == 2) {
            cout << 1 << endl;
            continue;
        }

        int a = 1;
        int b = 1;
        int i = 2;
        while (i != tmp) {
            int c = a + b;
            i++;
            a = b;
            b = c;
        }
        cout << b << endl;
    }
    return;
}

void f2() {
    const int MAX_N = 30;
    long long a[MAX_N + 5]; //  打表 记忆化存储
    a[1] = 1, a[2] = 1;
    // 给两个特殊值直接赋值
    for (int i = 3; i <= 30; i++) {
        a[i] = a[i - 1] + a[i - 2];
        // 每一项为前两项之和
    }
    int n;
    cin >> n;
    while (n--) {
        int ind;
        cin >> ind;
        cout << a[ind] << endl;
    }
    return;
}

int main() {
    // f1();
    f2();
    return 0;
}