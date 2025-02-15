#include <iostream>
using namespace std;

int main() {
    // 输入 m 和 k
    long long m;
    int k;
    cin >> m >> k;

    // 初始化计数器
    int count = 0;

    // 遍历 m 的每一位
    while (m > 0) {
        if (m % 10 == 3) { // 检查最低位是否是 3
            count++;
        }
        m /= 10; // 去掉最低位
    }

    // 判断是否等于 k
    if (count == k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
