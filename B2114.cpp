#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int MAX_LEN = 101; // 假设最大输入长度为100，加上终止符

char getBase(char base) {
    switch (base) {
        case 'A':
            return 'T';
        case 'T':
            return 'A';
        case 'G':
            return 'C';
        case 'C':
            return 'G';
        default:
            return '\0'; // 无效的碱基字符
    }
}

void complement(const char* input, char* output) {
    int len = strlen(input);
    for (int i = 0; i < len; ++i) {
        output[i] = getBase(input[i]);
    }
    output[len] = '\0'; // 添加字符串终止符
}

int main() {
    // 读取输入碱基链
    char input[MAX_LEN];
    cin >> input;

    // 生成互补碱基链
    char output[MAX_LEN];
    complement(input, output);

    // 输出结果
    cout << output << endl;

    return 0;
}
