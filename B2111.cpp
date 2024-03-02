#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // 读取阈值
    double threshold;
    cin >> threshold;

    // 读取两条DNA序列
    char dna1[505], dna2[505];
    // cout << "请输入第一条DNA序列: ";
    cin >> dna1;
    // cout << "请输入第二条DNA序列: ";
    cin >> dna2;

    // // 检查两条DNA序列的长度是否相同
    // if (dna1.length() != dna2.length()) {
    //     // cerr << "错误：两条DNA序列的长度不相同。" << endl;
    //     return 1;  // 退出程序，返回错误状态码
    // }

    // 计算相同碱基对的数量
    int matchingBasePairs = 0;
    for (size_t i = 0; dna1[i]; ++i) {
        if (dna1[i] == dna2[i]) {
            matchingBasePairs++;
        }
    }

    // 计算相同碱基对的比例
    double similarityRatio = (0.0 + matchingBasePairs) / strlen(dna1);

    // 输出结果
    if (similarityRatio >= threshold) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
