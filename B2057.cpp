#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mmax = 0;
    int tmp;
    while (n--) {
        cin >> tmp;
        mmax = max(mmax, tmp);
    }
    cout << mmax;
    return 0;
}