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
    long long n;
    cin >> n;

    // 遍历因数
    for (long long i = 2; i <= n / i; ++i) {
        if (n % i == 0) { // 找到一个因数
            long long other = n / i; // 另一个因数
            if (is_prime(other)) { // 如果较大的因数是质数
                cout << other << endl;
                return 0;
            }
            if (is_prime(i)) { // 如果较小的因数是质数
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}