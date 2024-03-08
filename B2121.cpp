#include <iostream>
#include <string>

using namespace std;

int mmax = 0, mmin = 105, cnt;
string s, str_max, str_min, tmp;

int main() {
    getline(cin, s);  // 一整行输入
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' || s[i] == ',' || s[i] == '.') {  // 判定单词末尾（注意中英符号区分）
            if (cnt > mmax) {                             // 最大值打擂台
                str_max = tmp;
                mmax = cnt;
            }
            if (cnt < mmin) {  // 最小值打擂台
                str_min = tmp;
                mmin = cnt;
            }
            cnt = 0;
            tmp.clear();  // 清除当前单词
        } else {
            tmp += s[i];  // 一般情况（记录单词字母以及其个数）
            cnt += 1;
        }
    }
    cout << str_max << endl
         << str_min << endl;
    return 0;
}
