#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e12;  // 节点编号的最大限制
int n;               // 操作次数
stack<char> st;      // 栈，用于记录溢出的操作
string c;            // 操作字符串
ll s;                // 当前节点编号

int main() {
    cin >> n >> s >> c;  // 输入操作次数、初始节点编号和操作字符串
    for (int i = 0; i < n; i++) {
        if (c[i] == 'L') {  // 向左移动
            if ((s << 1) > INF) {  // 如果编号溢出
                st.push('L');  // 将操作记录到栈中
                continue;
            }
            s = s << 1;  // 否则正常向左移动
        } else if (c[i] == 'R') {  // 向右移动
            if ((s << 1 | 1) > INF) {  // 如果编号溢出
                st.push('R');  // 将操作记录到栈中
                continue;
            }
            s = s << 1 | 1;  // 否则正常向右移动 s = 2 * s + 1
        } else  {  // 向上移动
            if (s == 1) continue;  // 根节点无法再向上
            if (st.size()) {  // 栈非空时弹出一个操作
                st.pop();
                continue;
            }
            s >>= 1;  // 否则直接向上移动  s = s / 2（取整）
        }
    }
    cout << s << "\n";  // 输出最终节点编号
    return 0;
}
