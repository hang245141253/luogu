#include <iostream>
using namespace std;

int main() {
    char str[10005]; // 定义足够大的字符数组
    cin.getline(str, 10005); // 读取一行输入，包括空格

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) { // 检查是否是字母
            if (islower(str[i])) {
                str[i] = (str[i] - 'a' - 1 + 26) % 26 + 'a'; // 小写字母循环位移
            } else if (isupper(str[i])) {
                str[i] = (str[i] - 'A' - 1 + 26) % 26 + 'A'; // 大写字母循环位移
            }
        }
        // 非字母字符保持不变
    }

    cout << str << endl; // 输出解密后的字符串
    return 0;
}