#include <iostream>
#include <queue>
#include <cstring> // 用于 memset
using namespace std;

const int MAXN = 505; // 假设最大地图大小为 500x500
bool visited[MAXN][MAXN]; // 访问标记
int dir[4][2] = { // 四个方向：上、下、左、右
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

struct Point {
    int x, y;
};

int x, y; // 地图的行数和列数
char grid[MAXN][MAXN]; // 地图，调整为从 (1,1) 开始输入

// 检查是否在地图范围内
bool inBounds(int nx, int ny) {
    return nx >= 1 && nx <= x && ny >= 1 && ny <= y;
}

// 使用 BFS 标记被洪水淹没的区域
void floodFill(int startX, int startY) {
    queue<Point> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        Point current = q.front();
        int cx = current.x;
        int cy = current.y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];

            // 修改洪水填充逻辑，确保跳过障碍物（'*'）
            if (inBounds(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '0') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> x >> y;

    // 读取地图，从 (1,1) 开始输入
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            cin >> grid[i][j];
        }
    }

    // 初始化访问标记
    memset(visited, false, sizeof(visited));

    // 从地图的左上角 (1,1) 开始进行洪水填充
    if (grid[1][1] == '0' && !visited[1][1]) floodFill(1, 1);

    // 统计未被淹没的重要区域
    int safeCount = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (grid[i][j] == '0' && !visited[i][j]) {
                safeCount++;
            }
        }
    }

    cout << safeCount << endl;
    return 0;
}
