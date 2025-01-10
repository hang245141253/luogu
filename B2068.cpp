#include <stdio.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        // 提取各位数字
        int qian = num / 1000;         // 千位
        int bai = (num / 100) % 10;    // 百位
        int shi = (num / 10) % 10;     // 十位
        int ge = num % 10;             // 个位

        // 判断是否满足条件
        if (ge - qian - bai - shi > 0) {
            count++;
        }
    }

    // 输出结果
    printf("%d\n", count);

    return 0;
}