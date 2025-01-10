#include <stdio.h>

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    // 模拟除法求第 n 位小数
    int mod = a % b; // 取余，初始余数
    for (int i = 1; i <= n; i++) {
        mod *= 10;         // 模拟下一位的运算
        if (i == n) {
            printf("%d\n", mod / b); // 输出第 n 位数字
            break;
        }
        mod %= b;          // 更新余数
    }

    return 0;
}
