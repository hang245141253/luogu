#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, h;
    cin >> n;
    vector<int> nxt;
    nxt.reserve(1e6 + 5);
    
    for (int i = 1; i <= n; i++)
        cin >> nxt[i];

    cin >> h;

    vector<int> ans;
    ans.reserve(1e6 + 5);

    // 1 4 2 6 5 3
    while (h != 0) {
        ans.push_back(h);
        h = nxt[h];
    }

    for (auto &i : ans) {
        cout << i << " ";
    }

    return 0;
}