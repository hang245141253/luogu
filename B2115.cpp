#include <iostream>

using namespace std;

int main() {
    string encryptedString;
    // cout << "请输入加密后的字符串: ";
    getline(cin, encryptedString);

    for (char& c : encryptedString) {
        if (isalpha(c)) {  // 检查是否是字母
            if ((c > 'a' && c <= 'z') || (c > 'A' && c <= 'Z')) {
                c--;  // 替换为前继字母
            } else if (c == 'a') {
                c = 'z';  // 替换为z
            } else if (c == 'A') {
                c = 'Z';  // 替换为Z
            }
        }
    }

    cout << encryptedString << endl;

    return 0;
}
