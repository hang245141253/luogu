#include <iostream>
#include <queue>
using namespace std;

// 定义变量
int n, a, b; // n: 总楼层数, a: 起始楼层, b: 目标楼层
int k[205]; // 每层楼的数字 K_i，表示电梯上下的层数
int flag[205]; // 记录每层楼是否访问过，以及到达该层楼的步数
queue<int> q; // 队列，用于 BFS 遍历楼层

// 尝试移动到下一层楼 nx，从当前楼层 x
void go(int nx, int x) {
    // 如果目标楼层 nx 超出范围，直接返回
    if (nx < 1 || nx > n) return;

    // 如果目标楼层 nx 已经访问过，直接返回
    if (flag[nx]) return;

    // 将目标楼层 nx 加入队列，并更新步数
    q.push(nx);
    flag[nx] = flag[x] + 1; // 到达 nx 的步数为到达 x 的步数加 1
    return;
}

// 调试函数：输出每层楼的访问状态
void print() {
    for (int i = 1; i <= n; i++) printf("%d ", flag[i]);
    printf("\n");
}

int main() {
    // 输入楼层数 n，起始楼层 a，目标楼层 b
    cin >> n >> a >> b;

    // 输入每层楼的数字 K_i
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    // 初始化 BFS
    q.push(a); // 将起始楼层加入队列
    flag[a] = 1; // 起始楼层标记为已访问，步数为 1

    // BFS 遍历楼层
    while (!q.empty()) {
        int idx = q.front(); // 当前楼层
        q.pop(); // 从队列中移除当前楼层

        // 如果到达目标楼层，输出步数并结束程序
        if (idx == b) {
            cout << flag[idx] - 1; // 输出步数（减去初始步数 1）
            return 0;
        }

        // 尝试向上移动 k[idx] 层
        go(idx + k[idx], idx);

        // 尝试向下移动 k[idx] 层
        go(idx - k[idx], idx);

        // 调试输出当前状态（可选）
        // print();
    }

    // 如果无法到达目标楼层，输出 -1
    cout << -1;
    return 0;
}