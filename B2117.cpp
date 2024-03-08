#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string process(string name) {
    if (!name.empty()) {
        name[0] = toupper(name[0]); // 将第一个字符转换为大写
        for (int i = 1; i < name.length(); i++) {
            name[i] = tolower(name[i]); // 将后续字符转换为小写
        }
    }
    return name;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;
        cout << process(str) << endl;
    }

    return 0;
}
