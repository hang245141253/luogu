#include <iostream>
using namespace std;

#define MAX_N 5000

int main() {
    bool led[MAX_N + 5] = {};
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            led[j] = !led[j]; // 将打开的灯关闭，将关闭的灯打开
        }
    }

    for (int i = 1; i <= n; i++) {
        if (led[i] == 0)
            cout << i << " ";
    }

    return 0;
}