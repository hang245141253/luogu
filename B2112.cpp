#include <iostream>
#include <cstring>

using namespace std;

const int MAX_LEN = 10; // 假设最大输入长度为10

char determineWinner(const char* choice1, const char* choice2) {
    if (strcmp(choice1, choice2) == 0) {
        return 'T'; // Tie
    } else if ((strcmp(choice1, "Rock") == 0 && strcmp(choice2, "Scissors") == 0) ||
               (strcmp(choice1, "Scissors") == 0 && strcmp(choice2, "Paper") == 0) ||
               (strcmp(choice1, "Paper") == 0 && strcmp(choice2, "Rock") == 0)) {
        return '1'; // Player1
    } else {
        return '2'; // Player2
    }
}

int main() {
    // 读取游戏次数
    int N;
    cin >> N;

    // 进行 N 次游戏
    for (int i = 0; i < N; ++i) {
        // 读取每一次游戏的选择
        char choice1[MAX_LEN], choice2[MAX_LEN];
        cin >> choice1 >> choice2;

        // 判断胜利者
        char winner = determineWinner(choice1, choice2);

        // 输出结果
        if (winner == 'T') {
            cout << "Tie" << endl;
        } else if (winner == '1') {
            cout << "Player1" << endl;
        } else {
            cout << "Player2" << endl;
        }
    }

    return 0;
}
