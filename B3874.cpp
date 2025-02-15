#include <iostream>
using namespace std;

/**
 * 此题是找顺序对的个数，可以利用归并排序
 * 
*/

long long cnt;
int *buff, num[300005];

void merge_sort(int *arr, int l, int r) {
    if (r - l <= 1) return ;
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    // merge
    /**
     * p1 = l：指向左子数组的起始位置
     * p2 = mid：指向右子数组的起始位置
     * k = 0：buff 数组的起始索引
     * 
    */
    int p1 = l, p2 = mid, k = 0;
    while (p1 < mid || p2 < r) {
        if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) {
            // 当左侧元素小于等于右侧元素时
            cnt += (r - p2); // 左侧元素 arr[p1] 小于右侧子数组中从 p2 到 r-1 的所有元素，形成顺序对
            buff[k++] = arr[p1++];
        } else {
            // 当左侧元素大于右侧元素时，不形成顺序对
            buff[k++] = arr[p2++];
        }
    }
    for (int i = l; i < r; i++) arr[i] = buff[i - l];
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    buff = new int[300005]; 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    merge_sort(num, 0, n);
    cout << cnt << endl;
    return 0;
}