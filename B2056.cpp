#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double sum = 0;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
    }
    printf("%d %.5lf", (int)sum, sum / n);
    return 0;
}