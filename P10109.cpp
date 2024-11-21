#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> head(305, -1);
int node[305], nxt[305], cnt;
vector<int> fa(305, -1);

void addEdge(int u, int v) {
    node[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int LCA(int u, int v) {
    set<int> vis;
    while (u != -1) {   // 顺着叶子u把所有的祖先都标记
        vis.insert(u);
        u = fa[u];
    }
    set<int> ans;
    ans.insert(1); // 大根堆，放个-1表示找不到
    while (v != -1) {
        // if (vis.find(v) != vis.end())   return v; // 这个是找最近公共祖先，题目不是找最近的，是所有祖先中最大的。
        if (vis.find(v) != vis.end()) {
            ans.insert(-v);
        }
        v = fa[v];
    }
    return -(*ans.begin());
}

int main() {
    int N;
    cin >> N;
    for (int u = 1, v; u < N; u++) {
        cin >> v;
        fa[u] = v;
        addEdge(u, v); // u->v
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int m;
        cin >> m;
        vector<int> emp(m);
        for (int i = 0; i < m; i++) cin >> emp[i];
        int lca = emp[0];
        for (int i = 1; i < m; i++) lca = LCA(lca, emp[i]);
        cout << lca << endl;
    }

    return 0;
}