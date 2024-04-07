#include <iostream>
using namespace std;

int main() {
    int arr[5][5]; // 声明一个5x5的矩阵

    // 读取矩阵元素
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> arr[i][j];
        }
    }

    // 寻找鞍点
    for (int i = 0; i < 5; ++i) {
        int max_val = arr[i][0]; // 当前行的最大值
        int max_col = 0; // 当前行最大值所在列
        // 找到当前行的最大值和其所在列
        for (int j = 1; j < 5; ++j) {
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
                max_col = j;
            }
        }
        // 检查当前列上的最大值是否为最小值
        bool saddle_point = true;
        for (int k = 0; k < 5; ++k) {
            if (arr[k][max_col] < max_val) {
                saddle_point = false;
                break;
            }
        }
        // 如果当前元素为鞍点，输出其行、列和值
        if (saddle_point) {
            cout << i + 1 << " " << max_col + 1 << " " << max_val << endl;
            return 0; // 找到一个鞍点即可，结束程序
        }
    }

    // 如果没有找到鞍点，输出not found
    cout << "not found" << endl;

    return 0;
}
