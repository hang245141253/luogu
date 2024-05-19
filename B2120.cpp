#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    string ans = "";
    while (cin >> str) {
        ans += to_string(str.size());
        ans += ',';
    }
    ans.pop_back();
    cout << ans << endl;
    return 0;
}