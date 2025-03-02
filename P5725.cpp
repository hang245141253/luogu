#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int num = 1;  // 计数器

    // 打印矩阵
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            printf("%02d", num++);  
        }
        printf("\n");  
    }

    printf("\n");  // 空行

    // 打印右下角对齐的三角形
    num = 1;  // 重新计数
    for (int i = 1; i <= n; i++) {  // 控制行数
        for (int j = i; j < n; j++) {  // 打印前导空格，保证右对齐
            printf("  ");
        }
        for (int j = 0; j < i; j++) {  // 打印数字
            printf("%02d", num++);
        }
        printf("\n");
    }

    return 0;
}
