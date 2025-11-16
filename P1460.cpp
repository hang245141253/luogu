#include <iostream>
#include <vector> 
using namespace std;

const int MAX_V = 25;
const int MAX_G = 15;

int v, g;  // 维他命种类数和饲料种类数
int vita[MAX_V + 5];  // 每种维他命的最小需求
int feed[MAX_G + 5][MAX_V + 5];  // 每种饲料提供的维他命含量
int bestCount = INT32_MAX;  // 最优解的饲料数量，初始化为最大值
vector<int> bestPath;  // 最优解的饲料编号集合

/*
1 2 3
0 0 0
0 0 1 [3]
0 1 0 [2]
0 1 1 [2, 3]
1 0 0 [1]
1 0 1 [1, 3]
1 1 0 [1, 2]
1 1 1 [1, 2, 3]

*/

bool check(const vector<int>& cur) {
    for (int i = 0; i < v; ++i) {
        if (cur[i] < vita[i])  // 如果某种维他命的累积量小于需求量，则不满足
            return false;
    }
    return true;  // 所有维他命需求都满足
}

void dfs(int idx, vector<int>& cur, vector<int>& path) {
    if (check(cur)) {
        if (path.size() < bestCount ||
            (path.size() == bestCount && path < bestPath)) {
            bestCount = path.size();  // 更新最优饲料数量
            bestPath = path;  // 更新最优饲料编号集合
        }
        return;  // 已经满足需求，返回
    }
    if (idx >= g)   return;  // 如果已经处理完所有饲料，直接返回

    dfs(idx + 1, cur, path);  // 不选当前饲料

    for (int i = 0; i < v; i++) {
        cur[i] += feed[idx][i];  // 选当前饲料，累加维他命
    }
    path.push_back(idx + 1);  // 将当前饲料编号加入路径（编号从1开始）
    dfs(idx + 1, cur, path); 
    path.pop_back();  // 回溯，移除当前饲料编号
    for (int i = 0; i < v; i++) {
        cur[i] -= feed[idx][i];  // 撤销当前饲料的维他命累加
    }
}



int main() {

    cin >> v;
    for (int i = 0; i < v; ++i) {
        cin >> vita[i];  // 输入每种维他命的最小需求量
    }
    cin >> g;
    for (int i = 0; i < g; ++i) {
        for (int j = 0; j < v; ++j) {
            cin >> feed[i][j];  // 输入每种饲料的维他命含量
        }
    }

    vector<int> cur(v, 0);  // 当前累积的维他命总量，初始化为0
    vector<int> path;  // 当前选择的饲料编号集合
    
    dfs(0, cur, path);  // 从第0个饲料开始进行深度优先搜索

    cout << bestCount << " ";  // 输出最优解的饲料数量
    for (int i = 0; i < bestPath.size(); ++i) {
        cout << bestPath[i];  // 输出最优解的饲料编号
        if (i < bestPath.size() - 1) cout << " ";  // 输出空格分隔
    }
    
    return 0;
}