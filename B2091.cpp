#include <iostream>
using namespace std;

#define MAX_N 1000

void init(int n, int arr[]) {
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    return ;
}

int main() {
    int a[MAX_N + 5], b[MAX_N + 5];

    int n;
    cin >> n;
    init(n, a);
    init(n, b);

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    cout << sum << endl;


    return 0;
}