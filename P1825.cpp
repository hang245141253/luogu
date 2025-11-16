#include <iostream>
#include <queue>
using namespace std;

// 定义节点结构体，表示迷宫中的一个格子
struct node {
    int x, y; // 节点的坐标
    int vis;  // 记录该节点的访问状态或到达该节点的最短时间
};

node n[305][305]; // 存储迷宫中每个格子的节点信息
char mmap[305][305]; // 存储迷宫的字符表示

// 定义四个方向的移动向量：上、下、左、右
int dir[4][2] = {
    -1, 0,  // 上
    1, 0,   // 下
    0, -1,  // 左
    0, 1    // 右
};

queue<node> q; // BFS 队列

// 打印迷宫中每个格子的访问状态，用于调试
void pri(int N, int M) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            printf("%3d", n[i][j].vis);
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    int N, M, sx, sy; // N 和 M 表示迷宫的行数和列数，sx 和 sy 表示起点坐标
    cin >> N >> M;

    // 读取迷宫的输入并初始化节点信息
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> mmap[i][j];
            n[i][j].x = i; // 初始化节点的 x 坐标
            n[i][j].y = j; // 初始化节点的 y 坐标
            if (mmap[i][j] == '#') { // 如果是玉米墙
                n[i][j].vis = -1; // 标记为不可访问
            } else if (mmap[i][j] == '@') { // 如果是起点
                sx = i; // 记录起点的 x 坐标
                sy = j; // 记录起点的 y 坐标
            }
        }
    }

    // 将起点加入 BFS 队列，初始访问时间为 0
    q.push({sx, sy, 0});

    // BFS 遍历迷宫
    while (!q.empty()) {
        node tmp = q.front(); // 取出队首节点
        q.pop();
        // if (mmap[tmp.x][tmp.y] == '=') {
        //     n[sx][sy].vis = 0;
        //     pri(N, M);
        //     cout << tmp.vis;
        //     return 0;
        // }
        for (int i = 0; i < 4; i++) {
            int x = tmp.x + dir[i][0]; // 计算新位置的 x 坐标
            int y = tmp.y + dir[i][1]; // 计算新位置的 y 坐标

            // 如果新位置已经访问过，跳过
            if (n[x][y].vis != 0) continue;

            if (mmap[x][y] == '.') { // 如果是草地
                n[x][y].vis = tmp.vis + 1; // 更新访问时间
                q.push(n[x][y]); // 加入队列
            } else if (mmap[x][y] >= 'A' && mmap[x][y] <= 'Z') { // 如果是滑梯端点
                // 遍历整个迷宫，找到与当前滑梯端点相连的另一个端点
                for (int i = 1; i <= N; i++) {
                    for (int j = 1; j <= M; j++) {
                        if (mmap[i][j] == mmap[x][y] && (i != x || j != y)) {
                            n[i][j].vis = tmp.vis + 1; // 更新访问时间
                            n[x][y].vis = tmp.vis + 1; // 更新当前端点的访问时间
                            q.push(n[i][j]); // 将另一个端点加入队列
                            n[i][j].vis = 0; // 重置访问状态
                        }
                    }
                }
            } else if (mmap[x][y] == '=') { // 如果是出口
                n[x][y].vis = tmp.vis + 1; // 更新访问时间
                cout << n[x][y].vis << endl; // 输出最短时间
                return 0; // 结束程序
            }
        }
    }

    return 0; // 如果没有找到出口，返回 0
}