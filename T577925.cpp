#include <iostream>
using namespace std;

const int N = 1e3 + 5;
bool vis[N];

int main() {
    int n, k;
    cin >> n >> k;
    int i = 0, s = 0, t = 0;
    do {
        ++i;
        i = (i - 1) % n + 1;
        if (!vis[i]) {
            ++s;
            if (s == k) {
                vis[i] = true;
                ++t;
                s = 0; 
            }
        }
    } while (t < n - 1);
    
    for (int j = 1; j <= n; ++j) {
        if (!vis[j]) {
            cout << j << endl;
            break;
        }
    }
    return 0;
}