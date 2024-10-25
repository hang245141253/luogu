#include <iostream>
using namespace std;

int main() {
    long long m, n, squ = 0, rec = 0;
    cin >> n >> m;

    for (long long x = 0; x <= n; x++)
        for (long long y = 0; y <= m; y++) {
            long long temp = min(x, y) + min(n - x, y) + min(n - x, m - y) + min(x, m - y);
            squ += temp;
            rec += n * m - temp;
        }
    cout << squ / 4 << " " << rec / 4;

    return 0;
}