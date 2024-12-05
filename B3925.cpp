#include <iostream>
using namespace std;

const int MAX_N = 10;
int cnt[MAX_N + 5];  // 每只猫操作时的鱼数

int main() {
    int N, i;
    cin >> N >> i;

    int fen = 1;  // 因为找最少，所以一开始从每份一条鱼开始往上面试

    // 要保证cnt[cat]中的鱼除了最后一次，每一次都是n - 1的倍数

    // 从最后一个猫倒着推找答案
    int cat = N;
    cnt[cat] = fen * N + i;  // 初始最后一只猫的鱼数

    while (cat >= 1) {

        if (cat == 1) {
            cout << cnt[1] << endl;
            break;
        }

        if (cnt[cat] % (N - 1) != 0) {
            fen++;
            cat = N;  // 重置循环
            cnt[cat] = fen * N + i;  // 初始最后一只猫的鱼数
            continue;
        }
        cnt[cat - 1] = cnt[cat] / (N - 1) * N + i;
        cat--;  // 换上一只猫
    }

    // for (int cat = 1; cat <= N; cat++) {
    //     printf("cnt[%d] = %d\n", cat, cnt[cat]);
    // }

    return 0;
}