#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000006];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    while (m--) {
        int tmp;
        cin >> tmp;
        int idx = lower_bound(arr, arr + n, tmp) - arr;
        if (*lower_bound(arr, arr + n, tmp) != tmp) {
            cout << -1;
        } else {
            cout << idx + 1;    // arr下标从0开始，题目要求从1开始，所以+1
        }
        m && printf(" ");
    }
    return 0;
}