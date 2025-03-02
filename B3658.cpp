#include <iostream>
#include <cmath>  // 引入 floor 函数
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    
    int res = floor(1.0 * x / y);  // 先转换为 double，再取 floor

    cout << res << endl;
    return 0;
}
