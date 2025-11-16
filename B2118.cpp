#include <iostream>
#include <cstring>
using namespace std;

bool isSubstring(const char* haystack, const char* needle) {
    size_t len1 = strlen(haystack);
    size_t len2 = strlen(needle);

    if (len2 > len1) return false; // 如果子串长度大于主串，直接返回 false

    for (size_t i = 0; i <= len1 - len2; ++i) {
        bool match = true;
        for (size_t j = 0; j < len2; ++j) {
            if (haystack[i + j] != needle[j]) {
                match = false;
                break;
            }
        }
        if (match) return true; // 找到子串
    }
    return false; // 未找到子串
}

int main() {
    char s1[1005], s2[1005];
    cin >> s1 >> s2;

    if (isSubstring(s1, s2)) // 判断 s2 是否是 s1 的子串
        cout << s2 << " is substring of " << s1 << endl;

    else if (isSubstring(s2, s1)) // 判断 s1 是否是 s2 的子串
        cout << s1 << " is substring of " << s2 << endl;
    else
        cout << "No substring" << endl;

    return 0;
}
