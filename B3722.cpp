#include <iostream>

using namespace std;

long long a[100005], b[100005]; // 使用 long long 防止大数据溢出

int main() {
    int n; // 售卖的月份数
    cin >> n;

    // 读取 A 型牛奶每个月的销量
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 读取 B 型牛奶每个月的销量
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long sum_a = 0, sum_b = 0; // 累计销量初始化

    // 遍历每个月，计算累计销量
    for (int i = 0; i < n; i++) {
        sum_a += a[i]; // 更新 A 型牛奶累计销量
        sum_b += b[i]; // 更新 B 型牛奶累计销量

        // 判断 B 型牛奶累计销量是否超过 A 型牛奶
        if (sum_b > sum_a) {
            cout << (i + 1) << endl; // 输出最少经过的月份数（从 1 开始计数）
            return 0; // 提前结束程序
        }
    }

    return 0; // 题目保证一定有解，因此程序不会走到这里
}
