#include <iostream>
using namespace std;

int main() {
    int sum = 0, a1, a2, a3, a4, a5;
    scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
    
    sum += a1 % 3;
    a1 /= 3;
    a5 += a1;
    a2 += a1;

    sum += a2 % 3;
    a2 /= 3;
    a3 += a2;
    a1 += a2;

    sum += a3 % 3;
    a3 /= 3;
    a4 += a3;
    a2 += a3;

    sum += a4 % 3;
    a4 /= 3;
    a5 += a4;
    a3 += a4;

    sum += a5 % 3;
    a5 /= 3;
    a1 += a5;
    a4 += a5;

    printf("%d %d %d %d %d\n", a1, a2, a3, a4, a5);
    printf("%d", sum);

    return 0;
}