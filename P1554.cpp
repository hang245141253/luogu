#include <iostream>
using namespace std;

int js[10]; // 计数排序

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
        for (int tmp = i; tmp; tmp /= 10)
            js[tmp % 10]++;
    for (int i = 0; i <= 9; i++)
        cout << js[i] << " ";

    return 0;
}
