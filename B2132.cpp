#include <iostream>
using namespace std;

// 判断是否是素数
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// 找出所有素数对
void find_prime_pairs(int n) {
    bool found = false; // 标记是否找到素数对
    for (int i = 2; i + 2 <= n; ++i) {
        if (is_prime(i) && is_prime(i + 2)) {
            cout << i << " " << i + 2 << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "empty" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    find_prime_pairs(n);
    return 0;
}
