#include <iostream>
#include <cctype>
using namespace std;

char str[260];

int main() {
    int cnt = 0;
    cin.getline(str, sizeof(str));
    for (int i = 0; str[i]; i++) {
        if (isdigit(str[i]))     cnt++;
    }
    cout << cnt << endl;
    return 0;
}