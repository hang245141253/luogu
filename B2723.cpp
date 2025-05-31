#include <stdio.h>

#define MAXN 1005  // 最大硬币数量，题目说最多1000个

typedef long long ll;  // 定义 long long 为 ll，方便写
ll coins[MAXN];     // 存放每枚硬币的面值
int used[MAXN] = {0}; // 记录每个硬币是否被拿走（0表示没被拿，1表示已被拿）

int main() {
    int n;

    // 读入硬币数量
    scanf("%d", &n);
    
    // 读入每枚硬币的面值
    for (int i = 0; i < n; i++) {
        scanf("%lld", &coins[i]);
    }

    // 两个人钱包中的总金额
    ll fj_total = 0;  // Farmer John的钱包
    ll bs_total = 0;  // Bessie 的钱包

    int turn = 0;      // 用于判断轮到谁，0 表示 FJ，1 表示 Bessie
    int picked = 0;    // 已经被拿走的硬币数量

    // 只要还有硬币没被拿，就继续游戏
    while (picked < n) {
        // 当前玩家钱包中的总金额
        ll current_sum = (turn == 0) ? fj_total : bs_total;

        int best_index = -1;  // 最佳选择的硬币编号
        ll best_value = -1;   // 最佳选择的面值（满足条件下最大）

        // 第一步：在可选硬币中找最大且 ≤ 钱包金额的硬币
        for (int i = 0; i < n; i++) {
            if (!used[i] && coins[i] <= current_sum && coins[i] > best_value) {
                best_value = coins[i];
                best_index = i;
            }
        }

        // 如果没有合适的硬币（钱包太穷了），就选剩下硬币中最小的一个
        if (best_index == -1) {
            ll min_value = -1;
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    if (min_value == -1 || coins[i] < min_value) {
                        min_value = coins[i];
                        best_index = i;
                    }
                }
            }
        }

        // 记录这枚硬币已被使用
        used[best_index] = 1;
        picked++;  // 拿走一枚

        // 加到当前玩家钱包中
        if (turn == 0) {
            fj_total += coins[best_index];
        } else {
            bs_total += coins[best_index];
        }

        // 换人
        turn = 1 - turn;
    }

    // 输出结果
    printf("%lld %lld\n", fj_total, bs_total);

    return 0;
}