#include <iostream>

using namespace std;

long long arr[1000005];        // 定义静态数组，最大支持 1,000,000 个元素
long long max_height = -1e18;  // 初始化最高值为极小值，以便后续进行比较
long long min_height = 1e18;   // 初始化最短值为极大值，以便后续进行比较

int main() {
    int n;     // 输入鹅的数量
    cin >> n;  // 读取鹅的数量

    // 输入每只鹅的身高，并找最高和最短的鹅
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // 读入第 i 只鹅的身高

        // 更新最高值，如果当前身高比最高鹅还高
        if (arr[i] > max_height) {
            max_height = arr[i];
        }

        // 更新最短值，如果当前身高比最短鹅还短
        if (arr[i] < min_height) {
            min_height = arr[i];
        }
    }

    // 计算并输出每只鹅比最高鹅短多少
    for (int i = 0; i < n; i++) {
        cout << (max_height - arr[i]);  // 最高身高 - 当前鹅的身高

        // 如果不是最后一个元素，加上空格
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;  // 换行

    // 计算并输出每只鹅比最短鹅高多少
    for (int i = 0; i < n; i++) {
        cout << (arr[i] - min_height);  // 当前鹅的身高 - 最短身高

        // 如果不是最后一个元素，加上空格
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;  // 换行

    return 0;  // 程序结束
}
