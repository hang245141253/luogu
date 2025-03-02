#include <iostream>

int main() {
    int k;
    std::cin >> k;

    int sum = 0;  // 总金币数
    int day = 0;  // 已经计算的天数
    int n = 1;    // 当前金币数（也是当前组的天数）

    while (day + n <= k) {  // 还能完整发放一组
        sum += n * n;
        day += n;
        n++;
    }

    // 处理最后一组未完整发放的部分
    sum += (k - day) * n;

    std::cout << sum << std::endl;
    return 0;
}
