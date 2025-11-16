#include <iostream>
#include <cmath> // abs()
using namespace std;

const int MAX_N = 10;
int n;
int s[MAX_N], b[MAX_N];
int min_diff = 1e9; // 初始为一个很大的数

// 枚举所有非空子集
void dfs(int idx, int total_s, int total_b, bool used) {
    if (idx == n) {
        if (used) { // 只考虑非空子集
            int diff = abs(total_s - total_b);
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
        return;
    }

    // 不选当前食材
    dfs(idx + 1, total_s, total_b, used);

    // 选当前食材
    int new_s = used ? total_s * s[idx] : s[idx]; // 如果之前没选，直接取当前食材酸度
    int new_b = total_b + b[idx];
    dfs(idx + 1, new_s, new_b, true);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }

    dfs(0, 1, 0, false);

    cout << min_diff << endl;

    return 0;
}