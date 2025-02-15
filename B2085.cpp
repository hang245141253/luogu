#include <iostream>
using namespace std;

// 判断是否为质数的函数
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int count = 0; // 记录找到的质数个数
    int number = 1; // 从 1 开始枚举
    while (count < n) {
        ++number;
        if (is_prime(number)) {
            ++count;
        }
    }

    cout << number << endl;
    return 0;
}