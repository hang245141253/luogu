#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int mid = (N + 1) / 2; // 中间行的位置

    for (int i = 1; i <= N; i++) {
        if (i == 1 || i == N || i == mid) {
            // 第一行、最后一行和中间行
            cout << "|";
            for (int j = 2; j <= N - 1; j++) {
                cout << "-";
            }
            cout << "|" << endl;
        } else {
            // 其他行
            cout << "|";
            for (int j = 2; j <= N - 1; j++) {
                cout << "x";
            }
            cout << "|" << endl;
        }
    }

    return 0;
}
