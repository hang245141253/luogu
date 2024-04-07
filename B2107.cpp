#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // 读取图像的行数和列数

    int image[100][100]; // 图像

    // 读取图像的像素点灰度
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> image[i][j];
        }
    }

    // 输出顺时针旋转90度后的图像
    for (int j = 0; j < m; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            cout << image[i][j];
            if (i != 0) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
