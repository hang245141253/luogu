#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double n;
    cin >> n;
    // printf("%.2lf", abs(n));
    if (n >= 0)
        printf("%.2lf", n);
    else
        printf("%.2lf", -n);
    return 0;
}