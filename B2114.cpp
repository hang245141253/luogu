#include <iostream>
#include <string>

using namespace std;

char getComplementaryBase(char base) {
    switch (base) {
        case 'A':
            return 'T';
        case 'T':
            return 'A';
        case 'G':
            return 'C';
        case 'C':
            return 'G';
        default:
            // cerr << "错误：无效的碱基字符" << endl;
            return '\0';
    }
}

string generateComplementaryChain(const string& input) {
    string complementaryChain = "";

    for (char base : input) {
        char complementaryBase = getComplementaryBase(base);
        complementaryChain += complementaryBase;
    }

    return complementaryChain;
}

int main() {
    // 读取输入碱基链
    string input;
    // cout << "请输入碱基链: ";
    cin >> input;

    // 生成互补碱基链
    string complementaryChain = generateComplementaryChain(input);

    // 输出结果
    cout << complementaryChain << endl;

    return 0;
}
