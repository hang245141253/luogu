#include <bits/stdc++.h>  // 引入所有标准库，加快编程速度
using namespace std;

#define ll long long  // 使用 ll 作为 long long 的别名，方便处理大数

// **函数 calc(x)：计算最多能用多少个奇妙数字凑成 x**
ll calc(ll x) {
    int ans = 0;  // 记录最多能选多少个奇妙数字
    ll tmp = 1;   // 当前要选的最小奇妙数字（初始为 1）

    // **贪心策略：尽可能选小的数，保证和不超过 x**
    while (x >= tmp) {
        ans++;     // 选择当前的奇妙数字
        x -= tmp;  // 从 x 中减去当前选的值
        tmp++;     // 下一个要尝试的奇妙数字
    }

    return ans;  // 返回最多能选的奇妙数字数量
}

// **主函数**
int main() {
    ll n;
    cin >> n;  // 读取输入 n

    ll ans = 0;  // 存储最终答案

    // **步骤 1：质因数分解 n**
    for (ll i = 2; i * i <= n; i++) {  // 遍历所有可能的质因数
        if (n % i == 0) {              // 如果 i 是 n 的因子
            int cnt = 0;               // 记录 i 作为质因子的指数（幂次）

            // **计算 i 在 n 的指数**
            while (n % i == 0) {
                cnt++;   // i 的指数加 1
                n /= i;  // 除掉这个 i
            }

            // **步骤 2：计算这个质因数指数对应的最多奇妙数字数目**
            ans += calc(cnt);
        }
    }

    // **步骤 3：n 可能仍然是一个大于 1 的质数**
    if (n != 1) {
        ans += calc(1);  // 质数 n 本身可以视为一个奇妙数字 (p^1)
    }

    cout << ans << "\n";  // 输出最终答案

    return 0;  // 返回 0，表示程序正常结束
}
