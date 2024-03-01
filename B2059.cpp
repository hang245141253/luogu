#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for (int i = (a | 1); i <= b; i += 2) {
        sum += i;
        // cout << i << endl;
    }
    cout << sum;
    return 0;
}