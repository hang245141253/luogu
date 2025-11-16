#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

const int MAX_L = 105; // 牛栏范围最大值
const int MAX_M = 15;  // 空调数量最大值

int N, M, ans = INT_MAX;
int nl[MAX_L]; // 牛栏冷却需求
int diff[MAX_L]; // 差分数组
struct air {
    int a, b, p, m;
    bool power; // 新增一个布尔变量表示空调是否开启
} ac[MAX_M];

bool check(int temp[]) {
    for (int i = 1; i <= 100; i++) { // 遍历牛栏范围
        if (temp[i] > 0) return false; // 如果冷却需求未满足，返回 false
    }
    return true; // 所有冷却需求都满足，返回 true
}

void dfs(int cost, int step) {
    if (step == M) { // 如果已经处理完所有空调
        int temp[MAX_L];
        memcpy(temp, nl, sizeof(nl)); // 复制牛栏冷却需求到临时数组
        for (int i = 0; i < M; i++) {
            if (ac[i].power) { // 如果空调开启
                for (int j = ac[i].a; j <= ac[i].b; j++) {
                    temp[j] -= ac[i].p; // 减去空调的冷却能力
                }
            }
        }
        if (check(temp)) ans = min(ans, cost); // 如果满足冷却需求，更新最小花费
        return;
    }

    dfs(cost, step + 1); // 不选当前空调，递归处理下一台空调

    ac[step].power = true; // 开启当前空调
    dfs(cost + ac[step].m, step + 1); // 选当前空调，递归处理下一台空调
    ac[step].power = false; // 关闭当前空调
}

void solve() {
    for (int mask = 0; mask < (1 << M); mask++) { // 枚举所有空调组合
        int temp[MAX_L];
        memcpy(temp, nl, sizeof(nl)); // 复制牛栏冷却需求
        int cost = 0;
        for (int i = 0; i < M; i++) {
            if (mask & (1 << i)) { // 如果当前空调被选中
                cost += ac[i].m; // 累加运行成本
                for (int j = ac[i].a; j <= ac[i].b; j++) {
                    temp[j] -= ac[i].p; // 减去冷却效果
                }
            }
        }
        if (check(temp)) ans = min(ans, cost); // 如果满足冷却需求，更新最小花费
    }
}

void solve2() {
    for (int mask = 0; mask < (1 << M); mask++) { // 枚举所有空调组合
        memset(diff, 0, sizeof(diff)); // 重置差分数组
        int cost = 0;
        for (int i = 0; i < M; i++) {
            if (mask & (1 << i)) { // 如果当前空调被选中
                cost += ac[i].m; // 累加运行成本
                diff[ac[i].a] += ac[i].p; // 更新差分数组
                diff[ac[i].b + 1] -= ac[i].p;
            }
        }
        int temp[MAX_L];
        memcpy(temp, nl, sizeof(nl));
        int cur = 0;
        for (int i = 1; i <= 100; i++) {
            cur += diff[i];
            temp[i] -= cur; // 应用差分数组更新冷却效果
        }
        if (check(temp)) ans = min(ans, cost); // 如果满足冷却需求，更新最小花费
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        for (int j = s; j <= t; j++) nl[j] += c; // 初始化牛栏冷却需求
    }
    for (int i = 0; i < M; i++) {
        cin >> ac[i].a >> ac[i].b >> ac[i].p >> ac[i].m; // 输入空调信息
        ac[i].power = false; // 初始化时空调均为关闭状态
    }
    // dfs(0, 0);
    solve();
    cout << ans << endl; // 输出最小花费
    return 0;
}