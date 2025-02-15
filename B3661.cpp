#include <iostream>

using namespace std;

int arr[10005];  // 定义静态数组，最大支持 10000 个学号

int main() {
    int n;  // 输入小朋友的总数
    cin >> n;

    // 输入所有学号
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 输出所有奇数学号
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1) {  // 判断是否为奇数（除 2 余 1）
            cout << arr[i];
            if (i != n - 1)
                cout << " ";  // 如果不是最后一个元素，输出空格
        }
    }
    cout << endl;  // 换行

    // 输出所有偶数学号
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {  // 判断是否为偶数（除 2 余 0）
            cout << arr[i];
            if (i != n - 1)
                cout << " ";  // 如果不是最后一个元素，输出空格
        }
    }
    cout << endl;  // 换行

    return 0;  // 程序结束
}
