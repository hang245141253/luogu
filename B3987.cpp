#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
    int n;
    cin >> n;
    

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cout << -a[i] << " ";  // 直接取 b_i = -a_i
    }
    cout << endl;

    return 0;
}