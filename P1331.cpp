#include <iostream>
#include <queue>
#include <cstring> // 为了使用 memset
using namespace std;

const int MAXN = 1000;
int R, C; // 棋盘的行数和列数
char board[MAXN][MAXN]; // 棋盘
bool visited[MAXN][MAXN]; // 访问标记
int dir[4][2] = { // 四个方向：上、下、左、右
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

// 替换 pair 为结构体
struct Point {
    int x, y;
};

// 检查是否在棋盘范围内
bool inBounds(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

// 使用 BFS 检查船只是否是一个合法的方形
bool bfs(int startX, int startY) {
    queue<Point> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    int minX = startX, maxX = startX, minY = startY, maxY = startY;

    // 修改队列的解构方式
    while (!q.empty()) {
        Point current = q.front();
        int x = current.x;
        int y = current.y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (inBounds(nx, ny) && !visited[nx][ny] 
                    && board[nx][ny] == '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});
                minX = min(minX, nx);
                maxX = max(maxX, nx);
                minY = min(minY, ny);
                maxY = max(maxY, ny);
            }
        }
    }

    // 检查是否是一个合法的方形
    for (int i = minX; i <= maxX; i++) {
        for (int j = minY; j <= maxY; j++) {
            if (board[i][j] != '#') {
                return false; // 如果方形区域内有空格，说明不是合法的方形
            }
        }
    }

    return true;
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    memset(visited, false, sizeof(visited)); // 初始化访问标记

    int shipCount = 0;
    bool valid = true;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '#' && !visited[i][j]) {
                if (!bfs(i, j)) {
                    valid = false; // 如果发现不是合法的方形，标记为无效
                    break;
                }
                shipCount++;
            }
        }
    }

    if (valid) {
        cout << "There are " << shipCount << " ships." << endl;
    } else {
        cout << "Bad placement." << endl;
    }

    return 0;
}