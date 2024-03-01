#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX_N 300

void bubble_sort(double* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    return ;
}

void init(int n, double *arr) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return;
}

int main() {
    int n;
    cin >> n;
    double arr[MAX_N + 5];
    double sum = 0;
    init(n, arr);
    // sort(arr, arr + n);   // 排序后掐头去尾
    bubble_sort(arr, n);     // 排序后掐头去尾

    double ans1 = 0;
    for (int i = 1; i < n - 1; i++) {
        ans1 += arr[i];
    }
    ans1 /= (n - 2);

    double ans2 = 0;
    for (int i = 1; i < n - 1; i++) {
        ans2 = max(ans2, fabs(ans1 - arr[i]));
    }

    printf("%.2lf %.2lf", ans1, ans2);

    return 0;
}