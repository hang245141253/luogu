#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>  // memset
using namespace std;

// 状态结构体：表示桶 A、桶 B 当前水量，以及已使用的操作次数
struct State {
    int a, b, step;
};

int X, Y, K, M;  // 桶 A 容量、桶 B 容量、最多操作次数、目标水量
bool vis[105][105][105];  
// vis[a][b][step] 表示：桶 A 有 a 升、桶 B 有 b 升，并且用了 step 步，这个状态是否访问过

int ans = 1e9;  // 最小差值，初始设为无穷大

// BFS 搜索所有 ≤K 步的状态
void bfs() {
    queue<State> q;

    memset(vis, 0, sizeof(vis));  // 访问数组重置

    // 初始状态：两个桶都是空的，步数为 0
    q.push({0, 0, 0});
    vis[0][0][0] = true;

    while (!q.empty()) {
        State now = q.front();
        q.pop();

        // 当前总水量
        int total = now.a + now.b;

        // 更新答案：计算与目标 M 的差值
        ans = min(ans, abs(M - total));

        // 如果已经用完 K 步，就不能再继续扩展
        if (now.step == K) continue;

        // ------------------------
        // 枚举 6 种可能的操作
        // ------------------------

        // 1. 倒空桶 A
        if (!vis[0][now.b][now.step + 1]) {
            vis[0][now.b][now.step + 1] = true;
            q.push({0, now.b, now.step + 1});
        }

        // 2. 倒空桶 B
        if (!vis[now.a][0][now.step + 1]) {
            vis[now.a][0][now.step + 1] = true;
            q.push({now.a, 0, now.step + 1});
        }

        // 3. 装满桶 A
        if (!vis[X][now.b][now.step + 1]) {
            vis[X][now.b][now.step + 1] = true;
            q.push({X, now.b, now.step + 1});
        }

        // 4. 装满桶 B
        if (!vis[now.a][Y][now.step + 1]) {
            vis[now.a][Y][now.step + 1] = true;
            q.push({now.a, Y, now.step + 1});
        }

        // 5. A → B 倒水
        int pourAtoB = min(now.a, Y - now.b);
        int na = now.a - pourAtoB;
        int nb = now.b + pourAtoB;
        if (!vis[na][nb][now.step + 1]) {
            vis[na][nb][now.step + 1] = true;
            q.push({na, nb, now.step + 1});
        }

        // 6. B → A 倒水
        int pourBtoA = min(now.b, X - now.a);
        na = now.a + pourBtoA;
        nb = now.b - pourBtoA;
        if (!vis[na][nb][now.step + 1]) {
            vis[na][nb][now.step + 1] = true;
            q.push({na, nb, now.step + 1});
        }
    }
}

// 深度优先搜索函数
// 参数：a - 桶 A 当前水量
//       b - 桶 B 当前水量
//       step - 已使用的操作次数
void dfs(int a, int b, int step) {
    if (step > K || vis[a][b][step]) return;

    vis[a][b][step] = true;

    int total = a + b;
    ans = min(ans, abs(M - total));

    // 6 种操作

    // 1. 桶 A 倒空
    dfs(0, b, step + 1);

    // 2. 桶 B 倒空
    dfs(a, 0, step + 1);

    // 3. 桶 A 装满
    dfs(X, b, step + 1);

    // 4. 桶 B 装满
    dfs(a, Y, step + 1);

    // 5. 桶 A → 桶 B 倒水
    int pourAtoB = min(a, Y - b);
    dfs(a - pourAtoB, b + pourAtoB, step + 1);

    // 6. 桶 B → 桶 A 倒水
    int pourBtoA = min(b, X - a);
    dfs(a + pourBtoA, b - pourBtoA, step + 1);
}

int main() {
    cin >> X >> Y >> K >> M;

    bfs();
    // dfs(0, 0, 0);
    cout << ans << endl;

    return 0;
}
