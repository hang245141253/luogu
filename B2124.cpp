#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end()); // 反转字符串

    return str == reversedStr;
}

int main() {
    string str;
    cin >> str;

    if (isPalindrome(str)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
