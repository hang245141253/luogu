#include <iostream>
#include <algorithm>
using namespace std;

// 定义全局静态数组，最大支持 10^5 个元素
const int MAX_N = 1e5 + 5;
int a[MAX_N];
int b[MAX_N];

int main() {
    int n;
    cin >> n;

    int max_a = -1e9, min_a = 1e9;  // 初始化最大值和最小值

    // 读取数列 a 并找出最大值和最小值
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
        min_a = min(min_a, a[i]);
    }

    // 选择常数 C = max_a + min_a
    int C = max_a + min_a;

    // 构造朋友数列 b，使得 a[i] + b[i] = C
    for (int i = 0; i < n; i++) {
        b[i] = C - a[i];
    }

    // 输出朋友数列 b
    for (int i = 0; i < n; i++) {
        cout << b[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
