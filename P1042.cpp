#include <bits/stdc++.h>   // 包含标准库头文件，用于提供C++标准库支持
using namespace std;       // 使用标准命名空间，简化代码中对标准库函数和对象的引用

int a[100005];              // 定义一个全局数组a，大小为100005，用于存储比赛的得分情况

int main() {                 // 主函数入口

    int cnt = 1;             // 定义一个计数器cnt，初始化为1，用于记录比赛得分的索引位置
    char ch;                 // 定义一个字符变量ch，用于读取输入数据

    // 读取输入直到遇到字符'E'或输入结束
    while (cin >> ch && ch != 'E') {
        if (ch == 'W')         a[cnt++] = 1; // 如果读取的字符是'W'，表示华华得分，数组a的相应位置设置为1
        else if (ch == 'L')    a[cnt++] = 2; // 如果读取的字符是'L'，表示对手得分，数组a的相应位置设置为2
        // 计数器cnt递增，准备记录下一个得分情况
    }

    // 11分制比赛结果的计算
    int i = 1, WW = 0, LL = 0; // 初始化索引i，华华得分WW和对手得分LL
    while (1) {               // 使用无限循环来处理11分制的比赛结果
        if (a[i] == 1)         WW++;  // 如果当前位置a[i]为1，华华得分增加1
        else if (a[i] == 2)    LL++;  // 如果当前位置a[i]为2，对手得分增加1
        else {                 // 遇到0值 说明结束
            cout << WW << ":" << LL << endl; // 输出当前比分
            WW = 0, LL = 0; // 重置得分计数器
            break;            // 退出循环
        }
        // 如果分差大于等于2且任意一方得分达到或超过11，则输出当前比分并重置得分计数器
        if (abs(WW - LL) >= 2 && (WW >= 11 || LL >= 11)) {
            cout << WW << ":" << LL << endl;
            WW = 0, LL = 0;
        }
        i++;                  // i移动到下一位，准备读取下一个得分情况
    }
    cout << endl;             // 输出一个空行，用于分隔11分制和21分制的输出结果

    // 21分制比赛结果的计算，逻辑与11分制相同，只是得分阈值变为21
    i = 1, WW = 0, LL = 0;    // 重置索引i和得分计数器
    while (1) {               // 再次使用无限循环来处理21分制的比赛结果
        if (a[i] == 1)         WW++;  // 华华得分增加1
        else if (a[i] == 2)    LL++;  // 对手得分增加1
        else {                 // 遇到0值 说明结束
            cout << WW << ":" << LL << endl; // 输出当前比分
            WW = 0, LL = 0;    // 重置得分计数器
            break;             // 退出循环
        }
        // 如果分差大于等于2且任意一方得分达到或超过21，则输出当前比分并重置得分计数器
        if (abs(WW - LL) >= 2 && (WW >= 21 || LL >= 21)) {
            cout << WW << ":" << LL << endl;
            WW = 0, LL = 0;
        }
        i++;                  // i移动到下一位
    }

    return 0;                 // 主函数返回0，表示程序正常结束
}