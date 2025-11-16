#include <iostream>
#include <cmath>
using namespace std;

const int N = 1001 * 1001; // 最大范围，题目要求处理到 1001 * 1001
const double eps = 1e-8; // 浮点数误差修正
bool is_lucky[N + 5]; // 标记每个数是否是幸运数
int next_lucky[N + 5]; // 记录每个数的下一个幸运数

// 初始化函数，预处理所有幸运数和下一个幸运数
void init(int a) {
    // 枚举所有数，判断是否是超级幸运数
    for (int i = 1; i <= N; i++) {
        int t = sqrt(i); // 计算 i 的平方根，修正浮点误差
        if (i >= a && t * t == i) // 如果 i 是大于等于 a 的完全平方数
            is_lucky[i] = true; // 标记为超级幸运数
        if (!is_lucky[i]) // 如果不是超级幸运数，跳过
            continue;

        // 标记所有超级幸运数的倍数为幸运数
        for (int j = i + i; j <= N; j += i)
            is_lucky[j] = true;
    }

    // 从后向前遍历，预处理每个数的下一个幸运数
    for (int i = N; i >= 1; i--)
        next_lucky[i] = is_lucky[i] ? i : next_lucky[i + 1];
}

int main() {
    int a, T;
    cin >> a >> T; // 输入超级幸运数的起始值 a 和查询次数 T

    init(a); // 调用初始化函数，预处理幸运数

    while (T--) {
        int x;
        cin >> x; // 输入需要判断的数 x
        if (is_lucky[x]) // 如果 x 是幸运数
            cout << "lucky" << endl; // 输出 "lucky"
        else
            cout << next_lucky[x] << endl; // 否则输出 x 幸运化后的结果
    }

    return 0;
}