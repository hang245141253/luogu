#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;

int n, m;
ll x;
vector<pair<int, int>> st;
int a[N], b[N];

int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        int p, c;
        cin >> p >> c;
        st.push_back(make_pair(p, c));
    }
    sort(st.begin(), st.end()); // 按站点位置排序

    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }

    vector<pair<int, int>> neg, pos;
    ll res = 0;

    // 将货车按需求分成两类
    for (int i = 1; i <= m; i++) {
        if (a[i] >= b[i])
            pos.push_back(make_pair(a[i] - b[i], i)); // 更偏向 A 市
        else
            neg.push_back(make_pair(a[i] - b[i], i)); // 更偏向 B 市
        res += 1LL * b[i] * x; // 计算去 B 市的初始成本
    }

    // 排序两类货车
    sort(neg.begin(), neg.end());         // 按 a-b 升序
    sort(pos.begin(), pos.end(), greater<>()); // 按 a-b 降序

    int l = 0, r = n - 1; // 分配站点的指针

    // 分配偏向 B 市的货车
    for (auto &i : neg) {
        while (r >= 0 && st[r].second == 0) r--; // 找到容量可用的站点
        // if (r < 0) break; // 无法分配更多站点
        res += 1LL * (a[i.second] - b[i.second]) * st[r].first;
        st[r].second -= 1; // 更新站点剩余容量
    }

    // 分配偏向 A 市的货车
    for (auto &i : pos) {
        while (l < n && st[l].second == 0) l++; // 找到容量可用的站点
        // if (l >= n) break; // 无法分配更多站点
        res += 1LL * (a[i.second] - b[i.second]) * st[l].first;
        st[l].second -= 1; // 更新站点剩余容量
    }

    cout << res * 2 << "\n"; // 输出最终结果
    return 0;
}
