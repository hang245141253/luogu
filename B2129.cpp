#include <iostream>
using namespace std;

double MAX(double a, double b, double c) {  // 所有值都要是double，因为题目说要保留3位小数。
    return max(a, max(b, c));               // 核心代码，三数求最大值。
}
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double m = MAX(a, b, c) / MAX(a + b, b, c) / MAX(a, b, b + c);  // 按照题意计算答案。
    printf("%.3lf", m);                                             // 保留三位小数。
    return 0;
}