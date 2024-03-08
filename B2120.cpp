#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    int word_lengths[305] = {0};
    int word_count = 0;
    string current_word = "";
    for (char c : input) {
        if (c == ' ') {
            if (!current_word.empty()) {
                word_lengths[word_count++] = current_word.size();
                current_word = "";
            }
        } else {
            current_word += c;
        }
    }

    if (!current_word.empty()) {
        word_lengths[word_count++] = current_word.size();
    }

    for (int i = 0; i < word_count; ++i) {
        cout << word_lengths[i];
        if (i != word_count - 1) {
            cout << ",";
        }
    }
    cout << endl;

    return 0;
}
