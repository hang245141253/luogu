#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        // 根据公式计算 (-1)^(i-1) * 1/i
        if (i % 2 == 1) {
            sum += 1.0 / i; // 奇数项相加
        } else {
            sum -= 1.0 / i; // 偶数项相减
        }
    }

    // 输出结果，保留 4 位小数
    printf("%.4lf\n", sum);

    return 0;
}