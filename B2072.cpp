#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // // 计算前 n 个正整数的和
    // int sum = n * (n + 1) / 2;
    
    int sum = 0;  // 初始化总和为 0

    // 使用循环累加
    for (int i = 1; i <= n; i++) {
        sum += i;  // 将当前数 i 加到总和中
    }

    // 输出结果
    printf("%d\n", sum);

    return 0;
}
