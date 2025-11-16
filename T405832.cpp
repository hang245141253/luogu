#include <iostream>
using namespace std;

int abs_primes[10005];
int cnt;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int reverse_num(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;  // 每次取末位加到新数上
        num /= 10;                  // 去掉末位
    }
    return rev;
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= 1000000 && cnt < n; i++) {
        if (is_prime(i) && is_prime(reverse_num(i))) {
            abs_primes[cnt++] = i;
        }
    }

    cout << abs_primes[n - 1] << endl;  // 输出第 n 个绝对素数

    return 0;
}