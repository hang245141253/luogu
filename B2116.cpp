#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// 函数用于解密规则1：循环左移3个位置
void decryptRule1(string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (isupper(str[i])) {
            str[i] = (str[i] + 3 - 'A') % 26 + 'A';  // 大写字母循环右移3位
        } else {
            str[i] = (str[i] + 3 - 'a') % 26 + 'a';  // 小写字母循环右移3位
        }
    }
}

// 函数用于解密规则2：逆序存储
void decryptRule2(string& str) {
    reverse(str.begin(), str.end());
}

// 函数用于解密规则3：大小写反转
void decryptRule3(string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else {
            str[i] = toupper(str[i]);
        }
    }
}

// 函数用于解密整个字符串
void decryptString(string& str) {
    // decryptRule3(str);
    // decryptRule2(str);
    decryptRule1(str);
}

int main() {
    string encrypted;
    cin >> encrypted;  // 读入加密的字符串
    decryptString(encrypted);
    cout << encrypted << endl;  // 输出解密后的字符串
    return 0;
}
