#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 中间行的位置
    int mid = (N + 1) / 2;

    for (int i = 1; i <= N; i++) {
        if (i == mid) {
            // 中间行："|---|"
            cout << "|";
            for (int j = 2; j <= N - 1; j++) {
                cout << "-";
            }
            cout << "|" << endl;
        } else {
            // 非中间行："|aaa|"
            cout << "|";
            for (int j = 2; j <= N - 1; j++) {
                cout << "a";
            }
            cout << "|" << endl;
        }
    }

    return 0;
}