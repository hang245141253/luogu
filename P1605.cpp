#include <iostream>
using namespace std;

// 迷宫最大尺寸
const int MAX_N = 6; // 1~5

// 地图及辅助变量
int n, m, t;                 // 迷宫行数、列数、障碍物数量
int sx, sy, fx, fy;          // 起点、终点坐标
int maze[MAX_N][MAX_N];      // 迷宫，1 表示障碍物，0 表示可走
int ans = 0;                 // 答案，统计路径数量

// 四个方向：上下左右
int dx[4] = {1, -1, 0, 0};   // x 方向增量
int dy[4] = {0, 0, 1, -1};   // y 方向增量

// DFS 函数
void dfs(int x, int y) {
    // 如果到达终点，路径数 +1
    if (x == fx && y == fy) {
        ans++;
        return;
    }

    // 递归四个方向
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; // 新的 x 坐标
        int ny = y + dy[i]; // 新的 y 坐标

        // 判断是否越界或遇到障碍或已走过
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && maze[nx][ny] == 0) {
            maze[nx][ny] = 1; // 标记为已走
            dfs(nx, ny);      // 递归
            maze[nx][ny] = 0; // 回溯，恢复状态
        }
    }
}

int main() {
    // 输入
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    // 初始化迷宫
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            maze[i][j] = 0; // 0 表示空地

    // 障碍物输入
    for (int i = 0; i < t; i++) {
        int ox, oy;
        cin >> ox >> oy;
        maze[ox][oy] = 1; // 1 表示障碍物
    }

    // 起点标记为已走
    maze[sx][sy] = 1;
    dfs(sx, sy);

    // 输出答案
    cout << ans << endl;

    return 0;
}