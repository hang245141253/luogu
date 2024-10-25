#include <iostream>
using namespace std;

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%.2lf\n", 1 / (1 / a + 1 / b));
    return 0;
}