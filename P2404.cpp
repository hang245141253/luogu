#include <iostream>
using namespace std;

// 定义全局变量 n 表示目标和，arr 用于存储当前分解的每一项
int n, arr[10];

// 深度优先搜索函数，step 表示当前分解的步数，sum 表示当前分解的和
void dfs(int step, int sum) {
    // 如果当前分解的和等于目标值 n
    if (sum == n) {
        // 如果最后一个分解的数就是 n，则不输出（避免只输出 n 本身）
        if (arr[step - 1] == n) return;
        // 输出当前分解方案
        for (int i = 1; i < step; i++) {
            // 除第一个数外，前面都加上加号
            (i - 1) && printf("+");
            printf("%d", arr[i]);
        }
        putchar('\n');
        // printf("=%d\n", sum); // 可选：输出等式右边的和
    }

    // 枚举下一个可选的数 i，i 从 1 到 n-sum
    for (int i = 1; i <= n - sum; i++) {
        // 保证分解的数递增或相等，避免重复
        if (i >= arr[step - 1]) {
            arr[step] = i;           // 记录当前选择的数
            dfs(step + 1, sum + i);  // 递归搜索下一个位置
        }
    }
    return ;
}

int main() {
    cin >> n;      // 输入目标值 n
    dfs(1, 0);     // 从第 1 步、和为 0 开始搜索
    return 0;
}