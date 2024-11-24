#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    bool div3 = (x % 3 == 0);
    bool div5 = (x % 5 == 0);
    bool div7 = (x % 7 == 0);

    if (div3 && div5 && div7) {
        cout << "3 5 7" << endl;
    } else if (div3 && div5) {
        cout << "3 5" << endl;
    } else if (div3 && div7) {
        cout << "3 7" << endl;
    } else if (div5 && div7) {
        cout << "5 7" << endl;
    } else if (div3) {
        cout << "3" << endl;
    } else if (div5) {
        cout << "5" << endl;
    } else if (div7) {
        cout << "7" << endl;
    } else {
        cout << "n" << endl;
    }

    return 0;
}
