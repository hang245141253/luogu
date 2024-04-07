#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // 读取矩阵的行数和列数

    int A[100][100]; // 矩阵A

    // 读取矩阵A的元素
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    // 输出矩阵A的转置
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
