#include <iostream>
using namespace std;

int main() {
    int chinese, math, english;
    cin >> chinese >> math >> english;

    int failCount = 0;
    if (chinese < 60) failCount++;
    if (math < 60) failCount++;
    if (english < 60) failCount++;

    if (failCount == 1) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
