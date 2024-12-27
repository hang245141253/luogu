#include <iostream>
#include <cmath>
using namespace std;

bool check(long long n, double mid) {
    return mid * mid * mid <= n;
}

double my_cbrt(long long n) {
    double min = 1, max = 1e15, mid;
    #define EPSL 1e-10
    while (max - min > EPSL) {
        mid = (max + min) / 2.0;
        if (check(n, mid))  min = mid;
        else    max = mid;
    }
    #undef EPSL
    return mid;
}

int main() {
    long long n;
    cin >> n;
    printf("%d\n", (int)my_cbrt(n));
    return 0;
}