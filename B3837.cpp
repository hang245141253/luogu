#include <iostream>
using namespace std;

int main() {
    int n;
    char ch = 'A';
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ch++;
            ch = (ch - 'A') % 26 + 'A';
        }
        cout << endl;
    }
    return 0;
}