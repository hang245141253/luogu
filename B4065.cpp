#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long mmax = 0;
    while (n--) {
        long long a;
        cin >> a;
        long long sum = 0;
        while (a) {
            sum += a % 10;
            a /= 10;
        }
        if (sum > mmax) {
            mmax = sum;
        }
    }
    cout << mmax << endl;
    return 0;
}