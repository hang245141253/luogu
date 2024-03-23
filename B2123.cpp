#include <iostream>
#include <string>

using namespace std;

string encodePType(string str) {
    string result = "";
    int count = 1; // 初始化相邻相同数字的个数为1
    // 遍历字符串，从第二个字符开始统计
    for (int i = 1; i < str.length(); i++) {
        // 如果当前字符与前一个字符相同，增加相邻相同数字的个数
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            // 如果当前字符与前一个字符不同，将前一个字符及其个数拼接到结果字符串中
            result += to_string(count) + str[i - 1];
            count = 1; // 重置相邻相同数字的个数为1
        }
    }

    // 处理最后一个字符及其个数
    result += to_string(count) + str[str.length() - 1];
    return result;
}

int main() {
    string str;
    cin >> str;
    cout << encodePType(str) << endl;
    return 0;
}
