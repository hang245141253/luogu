#include <bits/stdc++.h>
#define N 110
using namespace std;

int a[N][N];  // 地图 储存被轰炸的次数
int b[N][N];  // 最后一轮被轰炸的轮次

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    for (int l = 1; l <= x; l++) { // 遍历轮数
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++) { // 遍历轰炸区域
            for (int j = y1; j <= y2; j++) {
                a[i][j]++;
                b[i][j] = l;
            }
        }
    }
    while (y--) {
        int fx, fy;
        cin >> fx >> fy;
        if (!a[fx][fy]) {
            cout << "N\n";
        } else {
            cout << "Y " << a[fx][fy] << " " << b[fx][fy] << '\n';
        }
    }

    return 0;
}

/*
100 100 5 4
1 1 100 100
1 1 100 100
1 1 1 1
100 100 100 100
50 50 50 50
1 1
50 50
100 100
20 21

Y 3 3
Y 3 5
Y 3 4
Y 2 2
*/