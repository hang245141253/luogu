#include <iostream>
#include <unordered_map>
using namespace std;

#define MASK(n) ((1 << (n + 1)) - 2)  
// 计算 1~n 的二进制掩码 (二进制: 前面 n 位都是1，后面都是0)
// 例如: MASK(3)= 1110(二进制) = 14

unordered_map<int, int> ind; // 记录“某个位掩码”对应的列号（0-base下标）

int n;
int total_ans = 3;  // 只输出前3个解
int arr[20];        // 存储每一行的皇后放置列号 (1-based)

void print_one_result(int n) {
    // 输出一个解
    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" "); // 空格分隔
        printf("%d", arr[i]);   // 第 i 行的列号
    }
    printf("\n");
    total_ans -= 1;  // 已输出一个解，剩余要输出的解减1
    return ;
}

int dfs(int i, int t1, int t2, int t3) {
    // i: 当前要放皇后的行号
    // t1: 当前可放的列（二进制位1表示可以放）
    // t2: 当前可放的左对角线( \ ) （i+j 固定）
    // t3: 当前可放的右对角线( / ) （i-j+n 固定）
    // n: 棋盘大小
    
    if (i > n) {
        // 全部行放置完毕，得到一个解
        if (total_ans) print_one_result(n); // 只输出前3个解
        return 1;  // 返回一个解
    }
    
    int ans = 0; // 当前递归分支的可行解数量
    
    // 遍历 t1 中每个可用的列（lowbit方式）
    for (int t = t1; t; t -= (-t & t)) {
        int lowbit = -t & t; // 当前 lowbit
        int j = ind[lowbit]; // 由 lowbit 得到列号 j (0-base)
        
        // 检查左对角线/右对角线是否可放
        if ((t2 & (1 << (i + j - 1))) && (t3 & (1 << (i - j + n)))) {
            arr[i] = j; // 第 i 行放在第 j 列 (0-base)
            
            // 更新三个状态: 列、左对角线、右对角线
            ans += dfs(i + 1, 
                        t1 ^ (1 << j),              // 列 j 不可再用
                        t2 ^ (1 << (i + j - 1)),    // 左对角线标记
                        t3 ^ (1 << (i - j + n))    // 右对角线标记
                    );
        }
    }
    return ans; // 返回当前递归分支的解数量
}

int main() {
    scanf("%d", &n);
    total_ans = 3; // 只输出前三个解
    
    // 预先处理 ind 映射: (1 << i) -> i
    // 例如 (1<<3)=8, ind[8]=3
    for (int i = 0; i < 2 * n; i++) ind[1 << i] = i;
    
    // dfs(1, 所有列可用, 所有左对角线可用, 所有右对角线可用, n)
    // MASK(n)=前 n 位全1 (1~n 列可用)
    // MASK(2n-1)=前 2n-1 位全1 (对角线可能的索引最大为 2n-2)
    int ans = dfs(1, MASK(n), MASK(2 * n - 1), MASK(2 * n - 1));
    
    printf("%d\n", ans); // 输出总解数
    return 0;
}