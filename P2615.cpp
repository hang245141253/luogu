#include <iostream>
using namespace std;

int a[44][44];

int main() {
    int n;
    cin >> n;
    int x = 1, y = n / 2 + 1;
    a[x][y] = 1;  // 首先将 1 写在第一行的中间，(因为n是奇数，奇数/2+1是中间的数)。
    for (int i = 2; i <= n * n; i++) {
        // 若 (K-1) 在第一行但不在最后一列，则将 K 填在最后一行，(K-1) 所在列的右一列；
        if (x == 1 && y != n) {
            x = n, y++;
            a[x][y] = i;
        }  
        // 若 (K-1) 在最后一列但不在第一行，则将 K 填在第一列，(K-1) 所在行的上一行；
        else if (x != 1 && y == n) {
            x--, y = 1;
            a[x][y] = i;
        }  
        // 若 (K-1) 在第一行最后一列，则将 K 填在 (K-1) 的正下方；
        else if (x == 1 && y == n) {
            x++;
            a[x][y] = i;
        }  
        // 若 (K-1) 既不在第一行，也不在最后一列，
        else if (x != 1 && y != n) {
            // 如果 (K-1) 的右上方还未填数，
            if (a[x - 1][y + 1] == 0) {
                a[--x][++y] = i;  // 则将 K 填在 (K-1) 的右上方，
            } else {
                a[++x][y] = i;    // 否则将K 填在(K-1)的正下方。
            }
        }  
           
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}