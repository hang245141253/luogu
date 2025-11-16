#include <iostream>
using namespace std;

// 判断质数函数
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    // 从2开始判断每个数是否是质数
    for (int p = 2; p <= N; p++) {
        if (isPrime(p)) {
            int cnt = 0;
            // 暴力统计p在2..N中所有数的出现次数
            for (int i = 2; i <= N; i++) {
                int x = i;
                while (x % p == 0) {
                    cnt++;
                    x /= p;
                }
            }
            cout << p << " " << cnt << "\n";
            
        }
    }

    return 0;
}