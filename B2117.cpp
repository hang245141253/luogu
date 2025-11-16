#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void process(char* name) {
    size_t len = strlen(name);
    if (len > 0) {
        name[0] = toupper(name[0]); // 将第一个字符转换为大写
        for (size_t i = 1; i < len; ++i) {
            name[i] = tolower(name[i]); // 将后续字符转换为小写
        }
    }
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        char str[1005];
        cin >> str; // 读入字符串
        process(str); // 处理字符串
        cout << str << endl; // 输出处理后的字符串
    }

    return 0;
}
