#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tmp;
    int _1 = 0, _5 = 0, _10 = 0;
    while (n--) {
        cin >> tmp;
        if (tmp == 1)        _1++;
        else if (tmp == 5)   _5++;
        else if (tmp == 10 ) _10++;
    }
    printf("%d\n%d\n%d\n", _1, _5, _10);

    return 0;
}