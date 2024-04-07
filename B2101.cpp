#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n; // 读取行数和列数

    // 特判
    if (m == 1 && n == 1) {
        int num;
        cin >> num; // 读取矩阵元素
        cout << num << endl; // 直接输出矩阵元素，无需计算边缘元素之和
        return 0;
    }

    int arr[100][100]; // 声明一个大小为100x100的矩阵

    // 读取矩阵元素
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int sum = 0; // 存储边缘元素之和

    // 计算第一行和最后一行的元素之和
    for (int j = 0; j < n; j++) {
        sum += arr[0][j]; // 第一行
        if (m > 1) // 避免重复计算
            sum += arr[m - 1][j]; // 最后一行
    }

    // 计算第一列和最后一列的元素之和，避免重复计算第一行和最后一行的元素
    for (int i = 1; i < m - 1; i++) {
        sum += arr[i][0]; // 第一列
        if (n > 1) // 避免重复计算
            sum += arr[i][n - 1]; // 最后一列
    }

    // 输出边缘元素之和
    cout << sum << endl;

    return 0;
}
