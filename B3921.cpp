#include <iostream>
using namespace std;

int main() {
    int X, N, ans;
    cin >> X >> N;
    ans = (N + X - 1) % 7 + 1;
    cout << ans << endl;
    return 0;
}