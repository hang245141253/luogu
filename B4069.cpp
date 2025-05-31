#include <iostream>
#include <algorithm>
using namespace std;

string s[110];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        sort(s, s + n);

        string str = "";
        for (int i = 0; i < n; i++) {
            str += s[i];
        }

        bool flag = true;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] < str[i - 1]) {
                flag = false;
                break;
            }
        }
        cout << flag << endl;
    }
    return 0;
}