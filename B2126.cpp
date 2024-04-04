#include <iostream>
#include <string>

using namespace std;


char str[100];

int main() {
    scanf("%s", str);
    int k;
    string s;
    cin >> k >> s;

    int count = 1; // 保存当前字符的连续出现次数
    for (int i = 1; i < s.length(); ++i) {
        // 如果当前字符与前一个字符相同，则增加连续出现次数
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            // 如果当前字符与前一个字符不同，判断连续出现次数是否满足条件
            if (count >= k) {
                cout << s[i - 1] << endl; // 输出当前字符
                return 0;
            }
            // 重置连续出现次数，并更新前一个字符
            count = 1;
            s[i - 1] = s[i];
        }
    }

    // 判断最后一个字符的连续出现次数是否满足条件
    if (count >= k) {
        cout << s[s.size() - 1] << endl; // 输出最后一个字符
    } else {
        cout << "No" << endl; // 没有符合条件的字符
    }

    return 0;
}
