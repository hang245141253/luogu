#include <iostream>
using namespace std;

// 定义全局静态数组，最大支持 10^6 个元素，符合题目数据范围
const int MAX_N = 1e6 + 5;
int a[MAX_N];  // 存储小 S 队伍的战斗力
int b[MAX_N];  // 存储小 Q 队伍的战斗力

int main() {
    int n;
    cin >> n;

    int s_win = 0, q_win = 0;  // 初始化双方获胜局数

    // 读取小 S 队伍的战斗力
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 读取小 Q 队伍的战斗力
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // 比较每局比赛的战斗力
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            s_win++;  // 小 S 获胜
        } else if (a[i] < b[i]) {
            q_win++;  // 小 Q 获胜
        }
        // 如果相等则为平局，不做处理
    }

    // 输出双方的获胜局数
    cout << s_win << " " << q_win << endl;

    // 判断最终的胜负关系
    if (s_win > q_win) {
        cout << "S" << endl;
    } else if (s_win < q_win) {
        cout << "Q" << endl;
    } else {
        cout << "Tie" << endl;
    }

    return 0;
}
