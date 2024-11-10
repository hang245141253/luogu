#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    int k = a / b;
    cout << a - k * b << endl;
    return 0;
}