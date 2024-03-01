#include <iostream>
// #include <cctype>
using namespace std;

int main() {
    // 获取用户输入的一行字符
    char input_line[256];  // 假设输入的字符不超过256个
    cin.getline(input_line, sizeof(input_line));

    // 初始化数字字符计数器
    int digit_count = 0;

    // 遍历输入的字符，检查是否为数字字符
    for (int i = 0; input_line[i] != '\0'; ++i) {
    // if (input_line[i] <= '9' && input_line[i] >= '0')
        if (isdigit(input_line[i])) {
            digit_count++;
        }
    }

    // 输出结果
    cout << digit_count << endl;

    return 0;
}
