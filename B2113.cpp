#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LEN = 101; // 假设最大输入长度为100，加上终止符

void generateFamilyString(const char* input, char* result) {
    int len = strlen(input);

    for (int i = 0; i < len - 1; ++i) {
        result[i] = input[i] + input[i + 1];
    }

    // 处理最后一个字符
    result[len - 1] = input[len - 1] + input[0];
    result[len] = '\0'; // 添加字符串终止符
}

int main() {
    // 读取输入字符串
    char input[MAX_LEN];
    cin >> input;

    // 生成亲朋字符串
    char familyString[MAX_LEN];
    generateFamilyString(input, familyString);

    // 输出结果
    cout << familyString << endl;

    return 0;
}
