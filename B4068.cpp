#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3005;
const int C = 12000;

int arr[N], vis[C];

int main() {
    int n;
    cin >> n;

    arr[1] = 1;
    vis[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i - 1] - i <= 0 || vis[arr[i - 1] - i])
            arr[i] = arr[i - 1] + i;
        else
            arr[i] = arr[i - 1] - i;
        vis[arr[i]] = 1;
    }
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    return 0;
}