#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int maxn = 2e5 + 7;
int b[maxn], c[maxn];
long long sum;

struct item {
    int val, id;
} diff[maxn];

bool cmp(item a, item b) {
    return a.val < b.val;
}

int main() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)     cin >> b[i];
    for (int i = 1; i <= 2 * n; i++)     cin >> c[i];
    // cout << endl;
    for (int i = 1; i <= 2 * n; i++) {
        diff[i].val = b[i] - c[i];
        diff[i].id = i;
        // cout << diff[i].val << " ";
    }
    // cout << endl;
    sort(diff + 1, diff + 2 * n + 1, cmp);
    // for (int i = 1; i <= 2 * n; i++) {
    //     cout << diff[i].val << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= 2 * n; i++)
    //     cout << diff[i].id << " ";
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        sum += c[diff[i].id];
        // cout << c[diff[i].id] << " ";
    }
    // cout << endl;
    for (int i = n + 1; i <= 2 * n; i++) {
        sum += b[diff[i].id];
        // cout << b[diff[i].id] << " ";
    }
    cout << sum << endl;
    return 0;
}