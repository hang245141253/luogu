#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;  // 0, 1 不是素数
    for (int i = 2; i * i <= n; i++) {  // 只需判断到 sqrt(n)
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int A, B;
    cin >> A >> B;

    int count = 0;
    for (int i = A; i <= B; i++) {
        if (is_prime(i)) count++;
    }

    cout << count << endl;
    return 0;
}