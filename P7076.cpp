#include <iostream>
using namespace std;

int main() {
    unsigned long long n, m, c, k, animal_mask = 0, restriction_mask = 0;
    cin >> n >> m >> c >> k; // c 是饲料种类，但在后续的逻辑中没有实际使用

    // 读取动物编号，做按位或运算，计算所有动物编号的按位或结果
    for (int i = 0; i < n; i++) {
        unsigned long long animal;
        cin >> animal;
        animal_mask |= animal; // 更新 animal_mask，表示哪些位已经在现有的动物编号中出现了1
    }

    // 处理每条规则，用 restriction_mask 记录哪些位受到限制（必须为1）
    for (int i = 0; i < m; i++) {
        int p, q; // q 是饲料种类，在当前代码中没有实际使用
        cin >> p >> q;
        restriction_mask |= (1ULL << p); // 记录第 p 位必须为1的限制
    }

    restriction_mask = ~restriction_mask;
    animal_mask = animal_mask | restriction_mask;

    // 计算还可以自由选择的二进制位的数量
    int free_bits = 0;
    for (int i = 0; i < k; i++) {
        // 如果第 i 位不受限制，或者现有的动物编号中第 i 位已经有 1，那么该位可以自由选择
        if (animal_mask & (1ULL << i)) {
            free_bits++; // 增加自由选择的位数
        }
    }

    // 计算结果
    // (1ULL << 64) 会溢出，因此需要特殊处理
    if (free_bits == 64 && n == 0) {
        puts("18446744073709551616"); // 当 free_bits == 64 且 n == 0 时的特殊情况
    } else if (free_bits == 64 && n != 0) {
        cout << UINT64_MAX - n + 1; // 当 free_bits == 64 且 n != 0 时的特殊情况
    } else {
        cout << (1ULL << free_bits) - n << endl; // 计算可以添加的新动物数量
    }

    return 0;
}
