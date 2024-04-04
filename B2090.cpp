#include <iostream>
using namespace std;

void calculateAgeRatio(int *ages, int n) {
    int count[4] = {0}; // 用于统计四个年龄段的人数

    for (int i = 0; i < n; ++i) {
        if (*ages <= 18)
            count[0]++;
        else if (*ages <= 35)
            count[1]++;
        else if (*ages <= 60)
            count[2]++;
        else
            count[3]++;

        ages++; // 指针后移
    }

    // 计算百分比并输出
    printf("%.2f%%\n", (double)count[0] / n * 100);
    printf("%.2f%%\n", (double)count[1] / n * 100);
    printf("%.2f%%\n", (double)count[2] / n * 100);
    printf("%.2f%%\n", (double)count[3] / n * 100);
}

int main() {
    int n;
    cin >> n;

    int ages[100]; // 假设最多有100个患者
    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }

    calculateAgeRatio(ages, n);

    return 0;
}

// #include <iostream>
// using namespace std;

// #define MAX_N 100

// int arr[MAX_N + 5];

// int printff(const char str[], ...);

// int main() {
//     int n;
//     cin >> n;
//     int a = 0, b = 0, c = 0, d = 0;

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];

//         if (arr[i] <= 18) {
//             a++;
//         } else if (arr[i] <= 35) {
//             b++;
//         } else if (arr[i] <= 60) {
//             c++;
//         } else {
//             d++;
//         }
//     }

//     printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n%.2lf%%",
//            100.0 * a / n,
//            100.0 * b / n,
//            100.0 * c / n,
//            100.0 * d / n);


//     return 0;
// }