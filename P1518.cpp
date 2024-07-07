#include <bits/stdc++.h>
using namespace std;
int nex[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  // 牛和人的偏移量
int fx, fy;                                          // jon的初始位置
int cx, cy;                                          // 牛的初始位置
char a[20][20];
int main() {
    for (int i = 1; i <= 10; i++)  // step 1 储存数据 找牛和人的初始下标
    {
        for (int j = 1; j <= 10; j++) {
            cin >> a[i][j];
            switch (a[i][j]) {
            case 'F':
                fx = i, fy = j;
                break;
            case 'C':
                cx = i, cy = j;
                break;
            }
        }
    }

    int ck = 0;      // 牛的移动方向
    int fk = 0;      // 人的移动方向
    int time = 1e6;  // 较大值
    int se = 0;      // 时间
    // step 2 模拟人抓牛的运动,若抓到牛则退出并输出抓牛耗费的时间。
    while (se <= time)  // 在time时间内抓到牛
    {
        if (fx == cx && fy == cy)
            break;                                                           // 抓到牛
        cx += nex[ck][0], cy += nex[ck][1];                                  // 牛的移动
        if (a[cx][cy] == '*' || cx <= 0 || cx >= 11 || cy <= 0 || cy >= 11)  // 若牛碰到了障碍物或边界
        {
            cx -= nex[ck][0], cy -= nex[ck][1];  // 原地不动
            if (ck < 3)
                ck++;
            else
                ck = 0;  // 转向
        }
        fx += nex[fk][0], fy += nex[fk][1];                                  // 人的移动
        if (a[fx][fy] == '*' || fx <= 0 || fx >= 11 || fy <= 0 || fy >= 11)  // 若人碰到了障碍物或边界
        {
            fx -= nex[fk][0], fy -= nex[fk][1];  // 原地不动
            if (fk < 3)
                fk++;
            else
                fk = 0;  // 转向
        }
        se++;  // 时间的流逝
    }
    if (se >= time)
        cout << "0";
    else
        cout << se;
    return 0;
}