#include <iostream>
#include <vector>
using namespace std;

/**
 * 
 * 先写爆搜，超时：
void dfs(int n) {
    if (n <= c) {
        ans++; // 只能小范围数据用，这种方式破坏了记忆化搜索的核心思想和递归的逻辑结构。
        return;
    }
    
    dfs(n - a);
    dfs(n - b);
}
记忆化搜索的核心思想：
    递归函数的独立性：每个递归调用的状态（如 dfs(n)）都必须有明确的输入和输出
    状态与结果的唯一性：需要存储每个状态，而全局ans只能累积

递归的本质：
    分解问题
    解决子问题
    合并结果

转移方程：
    n作为根节点，只有两条路a、b可以走。题目求解是“多少种不同的游戏操作序列”
    n的结果是n-a n-b结果之和

 * 然后考虑优化dfs，添加记忆化搜索
 在递归问题中，返回值可以直接用来表示当前函数状态的计算结果
*/
int n, a, b, c;
int ans;
const int N = 2 * 1e5;
vector<int> dp(N + 5, -1); // 初始化记忆化数组，-1表示未计算

int dfs(int n) {
    if (n <= c)         return 1;       // 如果到达或小于c，计为一种方案
    if (dp[n] != -1)    return dp[n];   // 如果已经计算过，直接返回结果
    
    // 递归计算，并存储结果到dp数组
    dp[n] = (dfs(n - a) + dfs(n - b)) % int(1e9 + 7);
    return dp[n];
}

int main() {
    cin >> n >> a >> b >> c;

    ans = dfs(n);
    cout << ans << endl;

    return 0;
}
