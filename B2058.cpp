#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum_j = 0, sum_y = 0, sum_t = 0;
    int j, y, t;
    while (n--) {
        cin >> j >> y >> t;
        sum_j += j;
        sum_y += y;
        sum_t += t;
    }
    printf("%d %d %d %d", sum_j, sum_y, sum_t, sum_j + sum_y + sum_t);

        return 0;
}