#include <iostream>
using namespace std;

char firstUniqueChar(const char str[]) {
    const int CHAR_COUNT = 26;            // 小写字母的数量
    int charFrequency[CHAR_COUNT] = {0};  // 初始化字符频率数组

    // 统计每个字符出现的次数
    for (int i = 0; str[i] != '\0'; ++i) {
        charFrequency[str[i] - 'a']++;
    }

    // 遍历字符串，找到第一个出现次数为1的字符
    for (int i = 0; str[i] != '\0'; ++i) {
        if (charFrequency[str[i] - 'a'] == 1) {
            return str[i];
        }
    }

    // 如果没有找到，返回空字符 '\0'
    return '\0';
}

int main() {
    // 输入字符串
    char inputStr[1105];
    // cout << "请输入只包含小写字母的字符串: ";
    cin.getline(inputStr, sizeof(inputStr));

    // 找到第一个仅出现一次的字符
    char result = firstUniqueChar(inputStr);

    // 输出结果
    if (result != '\0') {
        cout << result << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
