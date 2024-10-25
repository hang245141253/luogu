#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int gcd2(int a, int b) {
    return b ? gcd2(b, a % b) : a; 
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    
    return 0;
}