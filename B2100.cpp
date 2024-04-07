#include <iostream>
using namespace std;

int main() {
    int N, i, j;
    cin >> N >> i >> j; // 读取输入的三个数

    // 输出同一行上的格子位置
    for (int col = 1; col <= N; col++) {
        cout << "(" << i << "," << col << ") ";
    }
    cout << endl;

    // 输出同一列上的格子位置
    for (int row = 1; row <= N; row++) {
        cout << "(" << row << "," << j << ") ";
    }
    cout << endl;

    // 输出同一左上到右下对角线上的格子位置
    int diff = min(i, j) - 1;
    int start_row = i - diff;
    int start_col = j - diff;
    while (start_row <= N && start_col <= N) {
        cout << "(" << start_row << "," << start_col << ") ";
        start_row++;
        start_col++;
    }
    cout << endl;

    // 输出同一左下到右上对角线上的格子位置
    diff = min(N - i + 1, j) - 1;
    start_row = i + diff;
    start_col = j - diff;
    while (start_row >= 1 && start_col <= N) {
        cout << "(" << start_row << "," << start_col << ") ";
        start_row--;
        start_col++;
    }
    cout << endl;

    return 0;
}
