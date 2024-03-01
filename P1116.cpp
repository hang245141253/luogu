#include <iostream>
using namespace std;

#define MAX_N 10000

int bubble(int* arr, int n) {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cnt++;
            }
        }
    }
    return cnt;
}

void init(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int main() {
    int arr[MAX_N + 5] = {};
    int n;
    cin >> n;
    init(arr, n);
    cout << bubble(arr,n);

    return 0;
}