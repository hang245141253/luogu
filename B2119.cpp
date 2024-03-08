#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;

    if (word.size() >= 2 && word.substr(word.size() - 2) == "er")
        word = word.substr(0, word.size() - 2);
    else if (word.size() >= 2 && word.substr(word.size() - 2) == "ly")
        word = word.substr(0, word.size() - 2);
    else if (word.size() >= 3 && word.substr(word.size() - 3) == "ing")
        word = word.substr(0, word.size() - 3);

    cout << word << endl;

    return 0;
}
