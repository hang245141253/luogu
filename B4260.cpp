#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int main() {
    int y, m, d, h, k;
    cin >> y >> m >> d >> h >> k;
    while (k--) {
        h++;
        if (h == 24) {
            h = 0;
            d++;
            if (d == 32 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)) {
                d = 1;
                m++;
            } else if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11)) {
                d = 1;
                m++;
            } else if (d == 30 && m == 2) {
                d = 1;
                m++;
            } else if (d == 29 && m == 2 && !isLeapYear(y)) {
                d = 1;
                m++;
            }
            if (m == 13) {
                m = 1;
                y++;
            }
        }

    }
    cout << y << " " << m << " " << d << " " << h << endl;
    return 0;
}