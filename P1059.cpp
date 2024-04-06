#include <iostream>
using namespace std;

#define MAX_N 1000

int arr[MAX_N + 5];
int bucket[MAX_N + 5];

int main() {
    int n = 0;
    int cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (bucket[arr[i]]) {
            continue;
        }
        cnt++;
        bucket[arr[i]]++;

    }

    cout << cnt << endl;
    for (int i = 0; i < 1001; i++) {
        if (bucket[i] == 0)
            continue;
        printf("%d ", i);
    }

    return 0;
}