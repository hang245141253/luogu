#include <iostream>
using namespace std;

int main() {
    char ch;
    cin >> ch;
    printf(
        "  %c\n"
        " %c%c%c\n"
        "%c%c%c%c%c\n"
    , ch, ch, ch, ch, ch, ch, ch, ch, ch);
    return 0;
}