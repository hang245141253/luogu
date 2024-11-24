#include <iostream>
using namespace std;

int main() {
    int distance;
    cin >> distance;

    double walkTime = distance / 1.2;
    double bikeTime = (distance / 3.0) + 27 + 23;

    if (walkTime < bikeTime) {
        cout << "Walk" << endl;
    } else if (bikeTime < walkTime) {
        cout << "Bike" << endl;
    } else {
        cout << "All" << endl;
    }

    return 0;
}
