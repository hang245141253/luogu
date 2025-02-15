#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int w, n;
    cin >> w >> n;

    vector<int> p(n);  // 纪念品价格列表
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());  // 价格从小到大排序

    int i = 0, j = n - 1;  // 双指针初始化
    int grp_cnt = 0;  // 分组计数

    while (i <= j) {
        if (p[i] + p[j] <= w) {
            i++;  // 最便宜的和最贵的一起分组
        }
        j--;  // 最贵的纪念品已经分组，右指针左移
        grp_cnt++;  // 每次循环至少分一组
    }

    cout << grp_cnt << endl;  // 输出最少分组数

    return 0;
}
