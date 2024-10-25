#include <iostream>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.3lf%%", 100.0 * b / a );
    return 0;
}