#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n; // 读取图像的行数和列数

    int arr1[100][100]; // 第一幅图像的像素矩阵
    int arr2[100][100]; // 第二幅图像的像素矩阵

    // 读取第一幅图像的像素矩阵
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr1[i][j];
        }
    }

    // 读取第二幅图像的像素矩阵
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr2[i][j];
        }
    }

    int total_pixels = m * n; // 总像素点数
    int same_pixels = 0; // 相同像素点数

    // 计算相同像素点数
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr1[i][j] == arr2[i][j]) {
                same_pixels++;
            }
        }
    }

    // 计算相似度并输出
    double similarity = (double)same_pixels / total_pixels * 100;
    printf("%.2lf", similarity);

    return 0;
}
