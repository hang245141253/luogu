#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    int g = x % 10;
    int s = x / 10 % 10;
    int b = x / 100;
    cout << g << s << b;
    return 0;
}