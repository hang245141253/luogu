#include <iostream>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.9lf", a / (b + 0.0));
    return 0;
}