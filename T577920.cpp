#include <iostream>
using namespace std;

const int N = 100010;   // 题目最大时间点范围（多开一点防止越界）
long long sum[N];       // 记录“变化量”，用于高效计算在某个时刻需要多少个篮子

int main() {
    int n;
    cin >> n;           // 输入：有 n 棵苹果树

    // 逐棵树读取信息
    while (n--) {
        int l, r, d;
        cin >> l >> r >> d;  // l：开始时间，r：结束时间，d：需要篮子数

        //在 l 这个时间点，篮子数 +d
        sum[l] += d;

        //在 r+1 这个时间点，篮子数 -d（表示 r 之后就不再需要这些篮子了）
        sum[r + 1] -= d;
    }

    long long maxn = 0; // 最多同时使用的篮子数

    // 计算前缀和，表示每个时刻实际需要的篮子数
    for (int i = 1; i <= 100000; i++) {
        sum[i] += sum[i - 1];  // 前缀和：sum[i] 表示第 i 时刻，当前一共需要的篮子数

        // 不断更新最大需要篮子数
        if (sum[i] > maxn) {
            maxn = sum[i];
        }
    }

//    for (int i = 1; i <= 15; i++) {
//         cout << sum[i] << " ";  // 输出每个时间点的变化量（调试用）
//     }
//     cout << endl;


    cout << maxn << endl;  // 输出最多需要的篮子数
    return 0;
}
