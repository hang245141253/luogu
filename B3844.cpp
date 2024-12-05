#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (char ch = i % 26 + 'A', j = 0; j < n; j++) {
            cout << ch++;
            ch = (ch - 'A') % 26 + 'A'; // 保证字符在A-Z之间
        }
        cout << endl;
    }
    return 0;
}