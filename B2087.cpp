#include <iostream>

using namespace std;

int arr[105];         // 定义静态数组，最大长度为100

int main() {
    int n;                // 数组长度
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];    // 读取数组元素
    }

    int m;                // 指定的数字
    cin >> m;

    int count = 0;        // 计数器，统计与 m 相同的数的个数
    for (int i = 0; i < n; i++) {
        if (arr[i] == m) {
            count++;      // 如果当前元素等于 m，计数器加1
        }
    }

    cout << count << endl; // 输出结果

    return 0;
}
