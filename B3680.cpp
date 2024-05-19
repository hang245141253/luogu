#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    string name;
    long long val;
} s[100005], h[100005];

int cmp(node x, node y) {
    return x.val > y.val;
}

int main() {
    int n, m;
    cin >> n >> m;
    int cntH = 0, cntS = 0;
    for (int i = 1; i <= n + m; i++) {
        string name;
        char v;
        long long val;
        cin >> name >> v >> val;
        if (v == 'H') {
            
            h[cntH].name = name;
            h[cntH].val = val;
            cntH++;
        } else {
            
            s[cntS].name = name;
            s[cntS].val = val;
            cntS++;
        }
    }

    sort(s, s + cntS, cmp);
    sort(h, h + cntH, cmp);

    cout << h[2].name << endl;
    for (int i = 5; i <= 8; i++) {
        cout << s[i].name << endl;
    }

    return 0;
}