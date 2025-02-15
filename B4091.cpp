#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> score(n);  // 孩子评分
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }

    vector<int> candy(n, 1);  // 初始化每个孩子至少有 1 颗糖果
    
    // 如果我的评分比相邻的孩子高，但我的糖果数量 不比 他多，
    // 那么我需要增加我的糖果数量，直到比他多 1 颗。
    bool changed = true;
    while (changed) {
        changed = false;

        // 不能左右一起看，那样是有后效性的

        // 从左到右遍历，保证（我i）左边评分低的孩子糖果少
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;  // 环形结构，处理相邻
            if (score[next] > score[i] && candy[next] <= candy[i]) {
                candy[next] = candy[i] + 1;
                changed = true;
            }
        }

        // 从右到左遍历，保证（我i）右边评分低的孩子糖果少
        for (int i = n - 1; i >= 0; --i) {
            int prev = (i - 1 + n) % n;  // 环形结构，处理相邻
            if (score[prev] > score[i] && candy[prev] <= candy[i]) {
                candy[prev] = candy[i] + 1;
                changed = true;
            }
        }
    }

    // 计算总糖果数
    long long total_candy = 0;
    for (int i = 0; i < n; ++i) {
        total_candy += candy[i];
    }

    cout << total_candy << endl;  // 输出最少需要的糖果数

    return 0;
}   