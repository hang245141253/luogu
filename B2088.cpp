#include <iostream>
#include <iomanip> // 用于控制小数精度

using namespace std;

int main() {
    // 书籍单价表，索引 0-9 对应 1-10 本书的价格
    double prices[10] = {28.9, 32.7, 45.6, 78.0, 35.0, 
                         86.2, 27.8, 43.0, 56.0, 65.0};
    
    int quantities[10]; // 用于存储每种书的购买数量
    double total = 0.0; // 总价
    
    // 读取输入的 10 个整数
    for (int i = 0; i < 10; i++) {
        cin >> quantities[i];
    }

    // 计算总价
    for (int i = 0; i < 10; i++) {
        total += prices[i] * quantities[i]; // 计算当前书籍的总价
    }

    // 输出总费用，保留 1 位小数
    cout << fixed << setprecision(1) << total << endl;

    return 0;
}
