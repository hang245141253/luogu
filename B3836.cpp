#include <iostream>
using namespace std;

int main() {
    int x, y, z, m, n, ans = 0;
    cin >> x >> y >> z >> n >> m;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m - i; j++) {
            if (x * i + j * y + (m - i - j) / z == n && (m - i - j) % z == 0)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
