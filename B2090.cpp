#include <iostream>
using namespace std;

#define MAX_N 100

int arr[MAX_N + 5];

int printff(const char str[], ...);

int main() {
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0, d = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] <= 18) {
            a++;
        } else if (arr[i] <= 35) {
            b++;
        } else if (arr[i] <= 60) {
            c++;
        } else {
            d++;
        }
    }

    printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n%.2lf%%",
           100.0 * a / n,
           100.0 * b / n,
           100.0 * c / n,
           100.0 * d / n);


    return 0;
}