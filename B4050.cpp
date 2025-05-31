#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int prime[MAX + 5]; // 0 表示质数, 1 表示非质数

void init() {
    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) continue; // 1: 不是质数
        for (int j = i; j <= MAX / i; j++) { // 优化筛法
            prime[j * i] = 1;
        }
    }
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int ans = 0, tmp = 1;
        while (true) {
            if (!prime[x]) { // x 是质数，直接用魔法攻击
                ans++;
                break;
            }
            x -= tmp; // 使用物理攻击
            ans++;
            if (x <= 0) {
                if (x < 0) ans = -1; // 不能正好打到 0
                break;
            }
            tmp *= 2; // 物理攻击翻倍
        }
        cout << ans << "\n";
    }
    return 0;
}
