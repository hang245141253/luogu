#include <iostream>
using namespace std;

const int N = 1005; // 题目范围最大不会超过1000
// int memo[N];

int dfs(int n) {
    // if (memo[n]) return memo[n];
    int cnt = 1; // 自身构成一种方案
    for (int i = 1; i <= n / 2; ++i) {
        cnt += dfs(i);
    }
    // memo[n] = cnt;
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}