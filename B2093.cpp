#include <iostream>
using namespace std;

#define MAX_N 10000

void init(int n, short* arr) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return ;
}

int main() {
    short arr[MAX_N + 5];
    int n;
    cin >> n;
    init(n, arr);

    short x;
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}