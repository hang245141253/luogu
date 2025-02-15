#include <cstdio>

int main() {
    int n;
    scanf("%d", &n); // 使用 scanf 输入整数 n

    // 初始化 e 和阶乘变量
    double e = 1.0;
    double factorial = 1.0;

    // 计算 e
    for (int i = 1; i <= n; i++) {
        factorial *= i;          // 计算 i!
        e += 1.0 / factorial;    // 累加 1/i!
    }

    // 使用 printf 输出结果，保留小数点后 10 位
    printf("%.10f\n", e);

    return 0;
}
