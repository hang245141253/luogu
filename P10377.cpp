#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = i;
    }

    int ans = 1e9;
    do {
        int curr_len = n;
        for (int i = 1; i < n; ++i) {
            curr_len += max(b[permutation[i - 1]], a[permutation[i]]);
        }
        ans = min(ans, curr_len);
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << ans << endl;

    return 0;
}