#include <iostream>
using namespace std;

#define MAX_N 100

int mmap[MAX_N + 5][MAX_N + 5];
int dir[13][2] = {
    {-2, 0},
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -2},
    {0, -1},
    {0, 0},
    {0, 1},
    {0, 2},
    {1, -1},
    {1, 0},
    {1, 1},
    {2, 0}};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    while (m--) {
        int x, y;  // 存坐标的临时变量
        cin >> x >> y;
        for (int i = 0; i < 13; i++) {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 1 || yy < 1 || xx > n || yy > n)
                continue;
            mmap[xx][yy] = 1;
        }
    }

    while (k--) {
        int x, y;  // 存坐标的临时变量
        cin >> x >> y;
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int xx = x + i;
                int yy = y + j;
                if (xx < 1 || yy < 1 || xx > n || yy > n)    continue;
                mmap[xx][yy] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            if (!mmap[i][j]) cnt++;
    
    cout << cnt << endl;

    return 0;
}