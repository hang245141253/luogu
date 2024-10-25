#include <bits/stdc++.h>
using namespace std;

const int N = 11, mod = 10;
int n, ans, vis[N][N][N][N][N];
// vector<vector<int>> possiblePasswords; // 用来存储符合条件的密码

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;

        // 循环枚举拨动的次数
        for (int j = 1; j <= 9; j++)
        {
            // 枚举拨动一个、拨动两个相邻的 j次的所有情况
            // 用vis记录反向拨回能得到的密码出现的次数
            vis[(a + j) % mod][b][c][d][e]++;
            vis[a][(b + j) % mod][c][d][e]++;
            vis[a][b][(c + j) % mod][d][e]++;
            vis[a][b][c][(d + j) % mod][e]++;
            vis[a][b][c][d][(e + j) % mod]++;
            vis[(a + j) % mod][(b + j) % mod][c][d][e]++;
            vis[a][(b + j) % mod][(c + j) % mod][d][e]++;
            vis[a][b][(c + j) % mod][(d + j) % mod][e]++;
            vis[a][b][c][(d + j) % mod][(e + j) % mod]++;
        }
    }

    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int u = 0; u <= 9; u++)
                    for (int v = 0; v <= 9; v++)
                        if (vis[i][j][k][u][v] == n)
                        {
                            ans++;
                            // possiblePasswords.push_back({i, j, k, u, v}); // 记录符合条件的密码
                        }

    // 输出可能的密码数量
    cout << ans << endl;

    // 输出具体的密码
    // for (auto &password : possiblePasswords)
    // {
    //     for (int num : password)
    //         cout << num;
    //     cout << endl; // 每行输出一个密码
    // }

    return 0;
}
