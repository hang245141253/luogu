#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k; // 读取矩阵的行数和列数

    int A[100][100]; // 矩阵A
    int B[100][100]; // 矩阵B
    int C[100][100]; // 结果矩阵C

    // 读取矩阵A的元素
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    // 读取矩阵B的元素
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> B[i][j];
        }
    }

    // 计算矩阵乘法，并将结果存储在矩阵C中
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            C[i][j] = 0; // 初始化C[i][j]为0
            for (int l = 0; l < m; ++l) {
                C[i][j] += A[i][l] * B[l][j]; // 矩阵乘法的累加过程
            }
        }
    }

    // 输出结果矩阵C
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
