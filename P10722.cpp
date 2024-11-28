#include <iostream>
#include <vector>
#include <map>
using namespace std;


const int N = 1e5;
vector<int> head(N + 5, -1);
char ans[N + 5];
int node[N + 5], nxt[N + 5], cnt;
int sum[N + 5];

void addEdge(int u, int v) {
    node[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

//  暴力搜索只能40分
void dfs(int u, int cnt) {
    cnt += sum[u]; // 父节点的翻转次数影响子节点的翻转状态
    //  所以通过cnt来向子节点传递父节点的反转状态
    //  这样可以一步直接计算出该子节点反转后的最终状态
    if (cnt & 1) ans[u] = (ans[u] == '0') ? '1' : '0';
    for (int i = head[u]; i != -1; i = nxt[i]) 
        dfs(node[i], cnt);
}

int main() {
    int n;
    cin >> n;
    for (int v = 2, u; v <= n; v++) {
        cin >> u;
        addEdge(u, v);
    }
    scanf("%s", ans + 1);
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        sum[a]++;
    }
    dfs(1, 0);

    cout << ans + 1 << endl;
    return 0;
}