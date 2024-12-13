#include <iostream>
#include <cmath>
using namespace std;

// 判断一个数是否为自幂数
bool isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = 0;

    // 计算数字的位数
    while (num > 0) {
        digits++;
        num /= 10;
    }

    num = originalNum; // 还原数字
    // 计算每一位的 digits 次方之和
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }

    // 如果次方和等于原数字，则为自幂数
    return sum == originalNum;
}

int main() {
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        // 判断并输出结果
        if (isArmstrong(num)) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }

    return 0;
}
