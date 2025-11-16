#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAXN = 9;
int n, m;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN][7]; // 位置 x, y 和当前血量 hp

int dx[4] = {-1, 1, 0, 0}; // 上下左右
int dy[4] = {0, 0, -1, 1};

struct State {
    int x, y, hp, step;
};

int bfs(int sx, int sy) {
    queue<State> q;
    q.push({sx, sy, 6, 0});
    visited[sx][sy][6] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            int nhp = cur.hp - 1;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == 0) continue; // 障碍

            if (nhp == 0) continue; // 到新位置前就死了 思考可以return -1吗
            if (visited[nx][ny][nhp]) continue;
            visited[nx][ny][nhp] = true;

            if (grid[nx][ny] == 4) nhp = 6; // 鼠标回血
            if (grid[nx][ny] == 3) return cur.step + 1; // 到家

            q.push({nx, ny, nhp, cur.step + 1});
        }
    }
    return -1; // 无法到家
}

int main() {
    cin >> n >> m;
    int sx, sy;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                sx = i;
                sy = j;
                grid[i][j] = 1; // 起点也视为普通空地
            }
        }

    cout << bfs(sx, sy) << endl;
    return 0;
}