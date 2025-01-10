#include <iostream>
using namespace std;

int main(void) {
    int n, sum, ok;
    // 读取实验组数 n，以及第一组（鸡尾酒疗法）的病例总数 sum 和有效病例数 ok
    cin >> n >> sum >> ok;

    double x = 1.0 * ok / sum;  // 计算鸡尾酒疗法的有效率 x

    while (n-- != 1) {  // 循环处理 n-1 个改进疗法的数据
        cin >> sum >> ok;
        double y = 1.0 * ok / sum;

        if (y - x > 0.05)             // 如果当前疗法有效率比鸡尾酒疗法高 5% 或更多
            cout << "better" << endl;  // 输出 "better"
        else if (x - y > 0.05)        // 如果当前疗法有效率比鸡尾酒疗法低 5% 或更多
            cout << "worse" << endl;   // 输出 "worse"
        else                           // 如果两者有效率差异在 5% 以内
            cout << "same" << endl;    // 输出 "same"
    }

    return 0;  // 程序结束
}
