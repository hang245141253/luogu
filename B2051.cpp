#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    // Check if the point is within the square, including the boundary
    if (x >= -1 && x <= 1 && y >= -1 && y <= 1) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
