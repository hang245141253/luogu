#include <iostream>
#include <cmath>

using namespace std;

// 判断一个数是否为素数
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int primeCount = 0; // 记录素数个数

    // 在给定范围内遍历每个数，统计素数的个数
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            primeCount++;
        }
    }

    cout << primeCount << endl; // 输出素数个数

    return 0;
}
