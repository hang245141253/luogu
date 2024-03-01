#include <iostream>
#include <string>

using namespace std;

string determineWinner(const string& choice1, const string& choice2) {
    if (choice1 == choice2) {
        return "Tie";
    } else if ((choice1 == "Rock" && choice2 == "Scissors") ||
               (choice1 == "Scissors" && choice2 == "Paper") ||
               (choice1 == "Paper" && choice2 == "Rock")) {
        return "Player1";
    } else {
        return "Player2";
    }
}

int main() {
    // 读取游戏次数
    int N;
    // cout << "请输入游戏次数 N: ";
    cin >> N;

    // 进行 N 次游戏
    for (int i = 0; i < N; ++i) {
        // 读取每一次游戏的选择
        string choice1, choice2;
        // cout << "请输入第 " << i + 1 << " 次游戏的选择（Player1 Player2）: ";
        cin >> choice1 >> choice2;

        // 判断胜利者
        string winner = determineWinner(choice1, choice2);

        // 输出结果
        cout << winner << endl;
    }

    return 0;
}
