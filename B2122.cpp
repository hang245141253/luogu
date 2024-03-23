// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//     string s;
//     while (cin >> s) {
//         reverse(s.begin(), s.end());
//         cout << s << endl;  // 换行。
//     }
//     return 0;
// }

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string str, fg;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if (int(str[i]) == ' ' || i == str.size() - 1) {
            reverse(fg.begin(), fg.end());
            cout << fg << endl;
            fg = "";
        } else {
            fg += str[i];
        }
    }
    return 0;
}

// #include <iostream>
// #include <string>
// #include <sstream> // 使用 stringstream 进行字符串分割

// using namespace std;

// // 函数用于翻转字符串
// string reverseWord(string word) {
//     int n = word.length();
//     for (int i = 0; i < n / 2; i++) {
//         swap(word[i], word[n - i - 1]);
//     }
//     return word;
// }

// int main() {
//     string sentence;
//     getline(cin, sentence); // 读取整行输入

//     // 使用 stringstream 进行字符串分割
//     stringstream ss(sentence);
//     string word;

//     // 逐个读取单词并翻转输出
//     while (ss >> word) {
//         cout << reverseWord(word) << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <string>

// using namespace std;

// // 函数用于翻转字符串
// string reverseWord(string word) {
//     int n = word.length();
//     for (int i = 0; i < n / 2; i++) {
//         swap(word[i], word[n - i - 1]);
//     }
//     return word;
// }

// int main() {
//     string sentence;
//     getline(cin, sentence);  // 读取整行输入
//     // 读取输入后手动处理回车符，将其从字符串中去除
//     if (!sentence.empty() && sentence.back() == '\r') {
//         sentence.pop_back();  // 删除回车符'\n'
//     }
//     /*
//     在 Windows 系统中，行尾的换行符是由两个字符组成的：
//     ASCII 13（回车符）和 ASCII 10（换行符）。
//     而在 Unix/Linux 系统中，行尾只有一个 ASCII 10（换行符）。
//     因此，你在输入的时候可能会包含回车符（ASCII 13
// if(a==b) cout<<"yes";），而 OJ 预期的输入格式中并不包含回车符。
//     */

//     // 遍历句子字符串，逐个提取单词并翻转输出
//     int start = 0;
//     for (int i = 0; i <= sentence.length(); i++) {
//         if (sentence[i] == ' ' || i == sentence.length()) {
//             string word = sentence.substr(start, i - start);
//             cout << reverseWord(word) << endl;
//             start = i + 1;
//         }
//     }

//     return 0;
// }

// #include <iostream>
// #include <sstream>
// using namespace std;

// int main() {
//     stringstream ss;
//     ss << "fuck" << 123 << " shit";

//     string s;
//     while (ss >> s) {
//         cout << s << endl;
//     }
//     return 0;
// }