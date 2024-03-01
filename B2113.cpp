#include <iostream>
#include <string>

using namespace std;

string generateFamilyString(const string& input) {
    string result = "";

    for (int i = 0; i < input.length() - 1; ++i) {
        char familyChar = input[i] + input[i + 1];
        result += familyChar;
    }

    // 处理最后一个字符
    char lastFamilyChar = input[input.length() - 1] + input[0];
    result += lastFamilyChar;

    return result;
}

int main() {
    // 读取输入字符串
    string input;
    // cout << "请输入一个长度大于等于 2，小于等于 100 的字符串: ";
    cin >> input;

    // 生成亲朋字符串
    string familyString = generateFamilyString(input);

    // 输出结果
    cout << familyString << endl;

    return 0;
}
