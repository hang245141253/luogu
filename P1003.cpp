#include <iostream>   // 包含输入输出流库，用于读入和输出数据
using namespace std;  // 使用标准命名空间

// 定义一个结构体 'DT'，用于存储每个地毯的信息
struct DT {
    int x, y, w, h;  // x 和 y 是地毯左下角的坐标，w 是宽度，height 是高度
};

DT arr[10005];  // 定义一个大小为 n 的数组，存储所有地毯的信息

int main() {
    int n, x, y;  // n 是地毯的数量，x 和 y 是要查询的点的坐标
    cin >> n;                 // 读入地毯数量

    // 循环读取每个地毯的位置信息
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].x >> arr[i].y >> arr[i].w >> arr[i].h;
        // 依次读入地毯的左下角坐标 (x, y) 和它的宽度 (w) 以及高度 (h)
    }

    cin >> x >> y;  // 读入需要查询的点的坐标 (x, y)

    // 从最后一个地毯开始倒序遍历，找到覆盖点的最上层地毯
    for (int i = n; i >= 1; i--) {
        // 检查点 (x, y) 是否在第 i 个地毯的范围内
        if (x >= arr[i].x && x <= arr[i].x + arr[i].w &&
            y >= arr[i].y && y <= arr[i].y + arr[i].h) {
            cout << i << endl;  // 输出地毯编号（从1开始）
            return 0;               // 程序结束，输出结果后直接返回
        }
    }

    // 如果遍历完所有地毯后仍未找到覆盖点的地毯，则输出 -1
    cout << "-1" << endl;  // -1 表示没有任何地毯覆盖该点
    return 0;              // 正常结束程序
}
