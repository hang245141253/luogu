#include <iostream>
#include <algorithm>
using namespace std;

long long arr[200005];

signed main() {
    long long N, C;
    cin >> N >> C;
    for (long long i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    long long ans = 0;
    //  遍历A， 利用A - C = B, 二分查找B
    // 有几个B那么就有几个ans
    for (long long i = 0; i < N; i++) {
        // 利用upper_bound - lower_bound 可以得到 单调序列中B的个数
        ans += upper_bound(arr, arr + N, arr[i] - C) - lower_bound(arr, arr + N, arr[i] - C);
    }
    cout << ans << endl;
    return 0;
}