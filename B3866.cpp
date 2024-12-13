#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 获取重新排列后的最大数和最小数的差值（不用迭代器）
int getNextNumber(int num) {
    string str = to_string(num); // 转为字符串操作
    char digits[3] = {str[0], str[1], str[2]}; // 转为字符数组
    
    // 排序求最大数
    sort(digits, digits + 3); // 从小到大排序
    int minNum = (digits[0] - '0') * 100 + (digits[1] - '0') * 10 + (digits[2] - '0');

    // 排序求最小数（反向遍历求最大数）
    int maxNum = (digits[2] - '0') * 100 + (digits[1] - '0') * 10 + (digits[0] - '0');

    return maxNum - minNum;
}

int main() {
    int num;
    cin >> num;

    int count = 0;

    while (num != 495) {
        num = getNextNumber(num);
        count++;
    }

    cout << count << endl;
    return 0;
}
