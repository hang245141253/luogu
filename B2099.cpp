#include <iostream>
using namespace std;

int main() {
    int arr[5][5]; // 声明一个 5x5 的矩阵

    // 读取矩阵
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> arr[i][j];
        }
    }

    int m, n;
    cin >> m >> n; // 读取需要交换的行号


    // 交换行
    for (int j = 0; j < 5; ++j) {
        int temp = arr[m - 1][j];
        arr[m - 1][j] = arr[n - 1][j];
        arr[n - 1][j] = temp;
    }

    // 输出交换后的矩阵
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
