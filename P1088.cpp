#include <iostream>
#include <algorithm>
using namespace std;

int a[10005];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < M; i++) {
        next_permutation(a, a + N);
    }

    for (int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}