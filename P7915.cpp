#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

/*
目标：构造一个长度为 2n 的回文序列 b。
限制：只能从序列 a 的左右两端取数。
要求：输出字典序最小的操作序列。
*/

const int N = 1000005;  // 定义数组的最大大小

int a[N];      // 输入序列
int first[N];  // 记录每个数字首次出现的位置
int match[N];  // 记录与a[]每个数字对应的匹配位置
int n;         // 数组长度的一半

bool solve(char op) {
    deque<int> q1, q2;           // 辅助双端队列
    string ops_front, ops_back;  // 记录操作序列的前半部分和后半部分

    ops_front.push_back(op);
    ops_back.push_back('L');  // 最后一个操作固定为 'L', 因为最后一步肯定只剩下一个元素
    // 考虑字典序最小就采取L

    if (op == 'L') {
        // 初始操作为 'L' 时，初始化队列
        for (int i = 2; i < match[1]; i++) q1.push_back(i);
        for (int i = n; i > match[1]; i--) q2.push_back(i);
    } else {
        // 初始操作为 'R' 时，初始化队列
        for (int i = 1; i < match[n]; i++) q1.push_back(i);
        for (int i = n - 1; i > match[n]; i--) q2.push_back(i);
    }

    while (!q1.empty() || !q2.empty()) {
        int x1 = q1.empty() ? 0 : q1.front();
        int x2 = q2.empty() ? 0 : q2.front();
        int y1 = q1.empty() ? 0 : q1.back();
        int y2 = q2.empty() ? 0 : q2.back();

        // 尝试匹配四种可能的组合
        if (x1 && y1 && match[x1] == y1) {
            ops_front.push_back('L');
            ops_back.push_back('L');
            q1.pop_front();
            q1.pop_back();
        } else if (x1 && y2 && match[x1] == y2) {
            ops_front.push_back('L');
            ops_back.push_back('R');
            q1.pop_front();
            q2.pop_back();
        } else if (x2 && y1 && match[x2] == y1) {
            ops_front.push_back('R');
            ops_back.push_back('L');
            q2.pop_front();
            q1.pop_back();
        } else if (x2 && y2 && match[x2] == y2) {
            ops_front.push_back('R');
            ops_back.push_back('R');
            q2.pop_front();
            q2.pop_back();
        } else {
            return false;  // 无法匹配，返回 false
        }
    }

    // 拼接操作序列并输出
    reverse(ops_back.begin(), ops_back.end());
    ops_front += ops_back;
    cout << ops_front << endl;
    return true;
}

int main() {
    int T;  // 测试用例数量
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        n *= 2;  // 实际的序列长度为 2n

        // 初始化数组
        for (int i = 1; i <= n; i++) {
            first[i] = 0;
            match[i] = 0;
        }

        // 读取输入并预处理匹配位置
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (first[a[i]]) {
                match[first[a[i]]] = i;
                match[i] = first[a[i]];
            } else {
                first[a[i]] = i;
            }
        }

        // 尝试以 'L' 和 'R' 开头的操作序列
        if (!solve('L') && !solve('R')) {
            puts("-1");  // 无解，输出 -1
        }
    }
    return 0;
}