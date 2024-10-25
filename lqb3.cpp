#include <iostream>
#include <map>
using namespace std;

/*
自动排序：map 会根据键值（key）自动排序，因此你插入数据后，map 会自动保持键的有序性。

唯一键：每个键在 map 中是唯一的，如果你试图插入一个已经存在的键，map 会更新该键对应的值（value），而不是插入一个新元素。

查找、插入、删除操作的时间复杂度：map 基于红黑树实现，这使得这些操作的时间复杂度是 O(log n)。
在这道题中的 map 用法
*/

int n;
int cnt = 0;
map<int, int> mp;

int main() {
    // 读取输入
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;  // 统计每个数字的出现频率
    }
    
    // 调整过程：当不同数字的种类数大于等于3时
    while(mp.size() >= 3) {
        if(cnt % 2 == 0) {  // 偶数次：处理最小值
            auto it = mp.begin();  // 获取最小值的迭代器
            auto next_it = next(it);  // 获取次小值的迭代器
            next_it->second += 1;  // 次小值的频率增加1
            it->second -= 1;  // 最小值的频率减少1
            if(it->second == 0) {
                mp.erase(it);  // 如果最小值频率为0，删除该元素
            }
        } else {  // 奇数次：处理最大值
            auto it = prev(mp.end());  // 获取最大值的迭代器 相当于解指针
            auto prev_it = prev(it);  // 获取次大值的迭代器
            prev_it->second += 1;  // 次大值的频率增加1
            it->second -= 1;  // 最大值的频率减少1
            if(it->second == 0) {
                mp.erase(it);  // 如果最大值频率为0，删除该元素
            }
        }
        cnt++;  // 每次调整后计数器增加1
    }
    
    // 输出结果：调整次数，最终的最小值和最大值
    int minv = mp.begin()->first;  // 最小值
    int maxv = prev(mp.end())->first;  // 最大值
    cout << cnt << " " << minv << " " << maxv << endl;

    return 0;
}