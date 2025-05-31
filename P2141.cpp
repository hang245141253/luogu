#include <stdio.h>

#define MAXN 105     // 最大数字个数
#define MAXV 10005   // 最大数值（数字不超过10000）

int a[MAXN];          // 存放输入的数字
int exist[MAXV] = {0}; // 用于快速判断一个数是否出现在集合中
int is_sum_target[MAXV] = {0}; // 标记某个数是否可以由两个不同的数相加得到

int main() {
    int n;

    // 输入数字个数
    scanf("%d", &n);

    // 读入所有的数，并标记每个数存在
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        exist[a[i]] = 1; // 标记这个数存在
    }

    // 枚举所有不同的两数之和 a[i] + a[j]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int sum = a[i] + a[j];
                // 如果这个和也在原数组中，并且不是 a[i] 本身或 a[j] 本身
                if (sum < MAXV && exist[sum]) {
                    is_sum_target[sum] = 1; // 标记这个数是由两个数相加得来的
                }
            }
        }
    }

    // 统计一共多少个数是由另外两个不同的数相加得来的
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (is_sum_target[a[i]]) {
            count++;
        }
    }

    // 输出答案
    printf("%d\n", count);

    return 0;
}
