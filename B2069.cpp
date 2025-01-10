#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // 初始化 q1, p1
    double q = 2.0, p = 1.0;
    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        sum += q / p; // 累加当前分数

        // 更新 q 和 p 的值
        double new_q = q + p;
        p = q;
        q = new_q;
    }

    // 输出结果，保留 4 位小数
    printf("%.4lf\n", sum);

    return 0;
}
