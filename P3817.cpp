#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<long long> a(n);  // 糖果盒子列表
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long eat_cnt = 0;  // 记录总共吃掉的糖果数

    for (int i = 0; i < n - 1; ++i) {
        long long sum = a[i] + a[i + 1];
        if (sum > x) {  // sum > x 时，需要吃掉多余的糖果
            long long excess = sum - x;  // 需要吃掉的糖果数
            eat_cnt += excess;
            if (a[i + 1] >= excess) {
                a[i + 1] -= excess;  // 优先从后面的盒子吃（无后效性）
            } else {
                a[i + 1] = 0;
                a[i] -= (excess - a[i + 1]);  // 如果后面的不够，再从前面的吃
            }
        }
    }

    cout << eat_cnt << endl;  // 输出最少吃掉的糖果数

    return 0;
}