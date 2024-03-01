#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double sum = 0.0;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;
    }
    printf("%.2lf", sum / n);
    return 0;
}