#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.find(s2) != string::npos)
        cout << s2 << " is substring of " << s1 << endl;

    else if (s2.find(s1) != string::npos)
        cout
            << s1 << " is substring of " << s2 << endl;
    else
        cout << "No substring" << endl;

    return 0;
}
