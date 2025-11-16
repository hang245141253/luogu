#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// likely表示x经常成立
#define likely(x) __bulitin_expect(!!(x), 1)
// unlikely表示x不经常成立
#define unlikely(x) __bulitin_expect(!!(x), 0)

// ll mem[21][21][21];
ll w(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    // else if(mem[a][b][c] != 0)
    //     return mem[a][b][c];
    if (a < b && b < c)
        // mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        // mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    // return mem[a][b][c];
}
int main() {
    ll a, b, c;
    while (1) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;
        // memset(mem, 0, sizeof(mem));
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}