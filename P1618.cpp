#include <iostream>
#include <algorithm>
using namespace std;

double a[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    double A, B, C;
    cin >> A >> B >> C;

    bool NO = true; 

    do {
        double num1 = a[1] * 100 + a[2] * 10 + a[3];
        double num2 = a[4] * 100 + a[5] * 10 + a[6];
        double num3 = a[7] * 100 + a[8] * 10 + a[9];

        if (num2 / num1 == B / A && num3 / num1 == C / A) {
            cout << num1 << " " << num2 << " " << num3 << endl;
            NO = false;
        }

    } while (next_permutation(a + 1, a + 10));

    if (NO) {
        cout << "No!!!";
    }

    return 0;
}