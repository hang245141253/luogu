#include <iostream>
using namespace std;

#define swap1(a, b) a ^= b, b ^= a, a ^= b

int a[105];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n / 2; i++) {
        swap1(a[i], a[n - 1 - i]);
    }

    for (int i = 0; i < n; i++) {
        // printf("a[%d] = %d\n", i, a[i]);
        printf("%d ", a[i]);
    }

    return 0;
}