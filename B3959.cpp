#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1e6;
int a[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int day = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] < day) continue;
        day++;
    }

    cout << --day;
    return 0;
}