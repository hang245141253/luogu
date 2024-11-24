#include <iostream>
using namespace std;

int main() {
    int weight;
    char express;
    cin >> weight >> express;

    int cost = 8;

    if (weight > 1000) {
        int excessWeight = weight - 1000;
        cost += ((excessWeight + 499) / 500) * 4;
    }

    if (express == 'y') {
        cost += 5;
    }

    cout << cost << endl;

    return 0;
}
