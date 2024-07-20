#include <stdio.h>

// 函数：将一个数字通过不断相加其各位直到成为单个数字
int reduce_to_single_digit(int num) {
    while (num > 9) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;  // 求出数字的最后一位
            num /= 10;        // 去掉数字的最后一位
        }
        num = sum;            // 更新数字为其各位之和
    }
    return num;               // 返回单个数字
}

// 函数：判断数字是否为幸运数
int is_lucky_number(long long num) {
    long long transformed = 0;
    int digit_count = 0;
    int sum_of_digits = 0;

    while (num > 0) {
        int digit = num % 10;
        if (digit_count % 2 == 0) { // 奇数位的处理（从1开始计数）
            digit = reduce_to_single_digit(digit * 7);  // 数字乘以7后简化为单个数字
        }
        transformed = transformed * 10 + digit;  // 将处理后的数字加到结果中
        sum_of_digits += digit;                  // 计算所有处理后的数字的和
        num /= 10;                               // 减去已处理的最后一位
        digit_count++;
    }

    return (sum_of_digits % 8 == 0) ? 1 : 0;    // 判断数字的和是否能被8整除
}

int main() {
    int n;
    scanf("%d", &n);  // 读取数字的数量

    while (n--) {
        long long num;
        scanf("%lld", &num);  // 读取每个数字
        if (is_lucky_number(num)) {
            printf("T\n");  // 如果是幸运数，输出'T'
        } else {
            printf("F\n");  // 如果不是幸运数，输出'F'
        }
    }

    return 0;
}
