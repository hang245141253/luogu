#include <iostream>
using namespace std;

#define MAX_N 100

void init(int n, int* arr, int &mmax) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mmax = max(mmax, arr[i]);
    }
    return ;
}

int main() {
    int arr[MAX_N + 5];
    int mmax = INT32_MIN;
    int sum = 0;
    int n;
    cin >> n;
    init(n, arr, mmax);

    for (int i = 0; i < n; i++) {
        if (arr[i] != mmax)  sum += arr[i];
    }
    cout << sum;
    return 0;
}