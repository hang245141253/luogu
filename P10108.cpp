#include <iostream>
#include <vector>
using namespace std;

const int INF = -0x3f3f3f3f;
int a[105], b[10005];

// dp[x] 第x关能获取最多的分数
vector<int> dp(10005, INF);
int ans = INF;

int main() {
    int N, M; // N关 M个通道
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> a[i]; // 通道
    for (int i = 0; i < N; i++) cin >> b[i]; // 关卡分值

    dp[0] = b[0];

    // 枚举关卡i
    for (int i = 0; i < N; i++) {
        // 枚举通道
        for (int j = 0; j < M; j++) {
            if (i + a[j] < N) {
                dp[i + a[j]] = max(dp[i] + b[i + a[j]], dp[i + a[j]]); // 先推出这个状态转移方程
                continue;
            }
            // 再根据转移方程，写出边界特判
            int tmp = max(dp[i], INF);
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;
}