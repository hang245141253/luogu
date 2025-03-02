#include <iostream>
#include <cmath>
using namespace std;

// 计算 PVIFA(i, n)
double PVIFA(double i, int n) {
    return (1 - pow(1 + i, - n)) / i;
}

int main() {
    int n, i;
    scanf("%d %d", &n, &i);

    // 输出表头
    printf("\t");
    for (int j = 1; j <= i; j++) {
        printf("%d%%%c", j, (j == i ? '\n' : '\t'));
    }

    // 计算并输出表格数据
    for (int a = 1; a <= n; a++) {
        printf("%d\t", a); // 输出行号
        for (int b = 1; b <= i; b++) {
            double rate = b / 100.0; // 计算利率
            printf("%.4f%s", PVIFA(rate, a), (b == i ? "\n" : "\t")); // 调用 PVIFA 计算
        }
    }
    
    return 0;
}
