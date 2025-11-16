#include <iostream>
using namespace std;

const int MAXN = 1000005;

int prime[MAXN]; // 记录每个数的最大质因子

void sieve(int n) {
    prime[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) continue;
        prime[i] = i; // 其最大质因子为其本身
        for (int j = 2; i * j <= n; j++) { // 将所有 i 的倍数枚举
            prime[i * j] = i;
        }
        
    }
}

int main() {
    int n, B;
    cin >> n >> B;

    sieve(n); 

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (prime[i] <= B) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}