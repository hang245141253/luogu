#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int num = 1;  // 计数器，从 1 开始

    for (int i = 0; i < n; i++) {  // 控制行数
        for (int j = i; j < n; j++) {  // 头动尾不动，终点固定为 n
            printf("%02d", num++);  // %02d 确保两位数，前面补 0
        }
        printf("\n");  // 换行
    }

    return 0;
}
