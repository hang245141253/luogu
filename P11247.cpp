#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int f[N];
vector<int> score[N + 2], a, b;

// 比较函数，用于对题目提升值从大到小排序
bool cmp(int i, int j) {
    return i > j;
}

int main() {
    int m, n, k;
    cin >> m >> n >> k; // 输入算法种类数 m，题目数 n，目标掌握程度 k
    a.resize(n), b.resize(n);  // 提升性能防止扩容耽误性能

    // 输入每道题目的知识点编号
    for (int i = 0; i < n; i++) // n个题目
        cin >> a[i];

    // 输入每道题目的提升值，并存入对应知识点的题目列表中
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        score[a[i]].emplace_back(b[i]); // 性能比push_back好。是当场构造
    }

    /*
    贪心策略：
        找到知识点最少需要的题目数，默认以这些题目的总和为答案
        考虑特殊情况：
            1.某个知识点题目不够用————直接-1
            2.不满足相同知识点的题目不能连续做：
                找到需要最多题目的那个知识点，想实现不能连续做，就往空隙中插入其他题目：
                    如果剩余题目够插空隙的，则输出最多题目的x2 - 1
                    找不到足够题目插空隙-1
    */
    vector<int> need(m + 2); // 每个知识点至少需要的题目数
    int ans = 0, mx_need = 0, mx_need_i = -1; // 总题目数、最大题目需求数及对应知识点编号

    // 遍历每个知识点
    for (int i = 1; i <= m; i++) {
        // 将该知识点的题目按提升值从大到小排序
        sort(score[i].begin(), score[i].end(), cmp);
        int sum = 0;
        // 计算达到目标掌握程度所需的最少题目数
        for (int j = 0; j < score[i].size(); j++) {
            sum += score[i][j];
            if (sum >= k) {
                need[i] = j + 1;
                break;
            }
        }
        // 如果该知识点总提升值不足以达到目标，直接输出 -1
        if (sum < k) {
            puts("-1");
            return 0;
        }
        ans += need[i]; // 累加总题目数
        // 更新最大需求题目数及对应知识点编号
        if (need[i] > mx_need) {
            mx_need = need[i];
            mx_need_i = i;
        }
    }

    // 检查是否可以避免连续学习相同知识点的题目
    // 把需要题目最多的先列出来， 然后它的空隙是 mx_need - 1 ，只要ans - mx_need剩余的题目足够插到空隙，就满足条件
    if (mx_need - 1 <= ans - mx_need) {
        cout << ans << endl;
        return 0;
    }

    int last = 0; // 其他知识点剩余的可选题目数
    for (int i = 1; i <= m; i++)
        if (i != mx_need_i)
            last += score[i].size() - need[i];

    // 判断是否可以通过调整满足条件，否则输出 -1
    cout << (mx_need - 1 <= ans - mx_need + last ? 2 * mx_need - 1 : -1) << endl;
    return 0;
}
