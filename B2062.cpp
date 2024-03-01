#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, n;
    cin >> a >> n;
    // cout << pow(a, n);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= a;
    }
    cout << ans;
    return 0;
}