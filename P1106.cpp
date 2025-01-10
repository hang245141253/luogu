#include <iostream>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    while (k--) {
        int j = 0;
        while (s[j + 1] && s[j] <= s[j + 1]) j++;   // 确认[j + 1]的位置有内容防止RE
        s.erase(j, 1);  // 从第j个位置删，删除1个字符
    }

    // 移除前导零
    while (!s.empty() && s[0] == '0')     s.erase(0, 1);
    
    // 如果删除后字符串为空，说明结果是 "0"
    cout << (s.empty() ? "0" : s) << endl;
    return 0;
}
