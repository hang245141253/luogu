#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    string maxName; // 保存最高分数学生的姓名
    int maxScore = -1; // 初始化最高分数为负数，确保比较时能正确更新最高分数

    for (int i = 0; i < N; ++i) {
        int score;
        string name;
        cin >> score >> name;

        // 如果当前学生的分数比最高分数高，则更新最高分数和对应的学生姓名
        if (score > maxScore) {
            maxScore = score;
            maxName = name;
        }
    }

    cout << maxName << endl; // 输出获得最高分数的学生姓名

    return 0;
}
