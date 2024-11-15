#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> dp(2005, INF);

int main() {
    dp[0] = 0;
    int N, L;
    cin >> N >> L;
    for (int i = 1, c, l; i <= N; i++) { // 枚举物品
        scanf("%d%d", &c, &l);
        for (int j = L; j >= 0; j--) {  // 倒着枚举包
            if (l >= j) dp[j] = min(dp[j], dp[0] + c); // 如果物品容量超过包，相当于只拿这个超容量的物品
            else    dp[j] = min(dp[j], dp[j - l] + c);
        }
    }

    if (dp[L] == INF) 
        cout << "no solution" << endl;
    else 
        cout << dp[L] << endl;
    

    return 0;
}