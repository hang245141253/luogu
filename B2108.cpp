#include <iostream>
#include <cmath> // round()函数四舍五入
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

    // 模糊处理图像
    int blurred[100][100]; // 模糊处理后的图像
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // 四周最外侧的像素点灰度值不变
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                blurred[i][j] = image[i][j];
            } else {
                // 中间各像素点新灰度值为该像素点及其上下左右相邻四个像素点原灰度值的平均（舍入到最接近的整数）
                blurred[i][j] = round((image[i][j] + image[i-1][j] + image[i+1][j] + image[i][j-1] + image[i][j+1]) / 5.0);
            }
        }
    }

    // 输出模糊处理后的图像
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << blurred[i][j];
            if (j != m - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
