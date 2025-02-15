#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> t(n);  // pair<接水时间, 原始编号>, t: time
    for (int i = 0; i < n; ++i) {
        cin >> t[i].first;
        t[i].second = i + 1;  // 编号从 1 开始
    }

    // 按接水时间排序
    sort(t.begin(), t.end());

    // 输出排队顺序
    for (int i = 0; i < n; ++i) {
        cout << t[i].second;
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    // 计算总等待时间
    long long tot_wt = 0;   // 总等待时间
    long long cur_wt = 0;   // 当前等待时间
    for (int i = 0; i < n; ++i) {
        tot_wt += cur_wt;
        cur_wt += t[i].first;
    }

    // 计算平均等待时间
    double avg_wt = (double)tot_wt / n;

    // 输出平均等待时间，保留两位小数
    cout << fixed << setprecision(2) << avg_wt << endl;

    return 0;
}
