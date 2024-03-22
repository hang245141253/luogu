#include <iostream>
using namespace std;

// 计算一个数的所有因数之和
int sumOfDivisors(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        if (sumOfDivisors(i) == i) {
            cout << i << endl; // 输出完全数
        }
    }

    return 0;
}


// 递归
// #include <iostream>
// using namespace std;

// // 递归函数：计算一个数的所有因数之和
// int sumOfDivisors(int num, int divisor = 1, int sum = 0) {
//     if (divisor > num / 2) {
//         return sum;
//     }
//     if (num % divisor == 0) {
//         sum += divisor;
//     }
//     return sumOfDivisors(num, divisor + 1, sum);
// }

// int main() {
//     int n;
//     cin >> n;

//     for (int i = 2; i <= n; ++i) {
//         if (sumOfDivisors(i) == i) {
//             cout << i << endl; // 输出完全数
//         }
//     }

//     return 0;
// }
