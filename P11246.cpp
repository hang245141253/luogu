#include <cmath>
#include <iostream>
using namespace std;

int n, ans = 0x3f3f3f3f;
int dp[100005];

int dfs(int x, int cnt) {
    if (x <= 0) {
        ans = min(ans, cnt);
        dp[x] = ans;
    }
    
    for (int i = sqrt(x); i >= 1; i--) {
        int chai = x - i * i;
        if (dp[chai]) return dp[chai];
        dp[chai] = dfs(chai, cnt + 1);
    }
    return dp[x];
}

int main() {
    cin >> n;
    dfs(n, 0);
    cout << ans << endl;

    // // 从dp[1]开始往上填
    // for (int i = 1; i <= n; i++) {
    //     dp[i] = i; // 初始化一个极大值
    //     for (int j = 1; j <= sqrt(i); j++) {
    //         dp[i] = min(dp[i], dp[i - j * j] + 1);
    //     }
    // }
    // cout << dp[n] << endl;
    return 0;
}