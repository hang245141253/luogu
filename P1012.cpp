#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 比较函数，定义拼接后的偏序关系
bool compare(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;
    vector<string> nums(n);
    // 输入数字并转化为字符串
    for (int i = 0; i < n; ++i)     cin >> nums[i];
    // 按照偏序关系排序
    sort(nums.begin(), nums.end(), compare);
    // 拼接结果
    string result;
    for (const string &num : nums)     result += num;
    // 输出结果
    cout << result << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;

// // 获取全排列中最大拼接结果
// string getMaxConcatenation(vector<string>& nums) {
//     string maxNumber = "";
//     // 首先按字典序排序，以便使用 next_permutation
//     sort(nums.begin(), nums.end());
//     do {
//         string currentConcat = "";
//         // 将当前排列拼接成一个字符串
//         for (const string& num : nums) {
//             currentConcat += num;
//         }
//         // 更新最大拼接结果
//         if (currentConcat > maxNumber) {
//             maxNumber = currentConcat;
//         }
//     } while (next_permutation(nums.begin(), nums.end())); // 使用 next_permutation 生成下一个排列

//     return maxNumber;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<string> nums(n);

//     // 读取输入并将每个整数转为字符串
//     for (int i = 0; i < n; ++i) {
//         cin >> nums[i];
//     }

//     // 获取最大拼接结果
//     string result = getMaxConcatenation(nums);

//     // 如果结果以 '0' 开头，说明所有数都是 0
//     if (result[0] == '0') {
//         cout << "0" << endl;
//     } else {
//         cout << result << endl;
//     }

//     return 0;
// }