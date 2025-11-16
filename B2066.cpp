#include <stdio.h>
#include <math.h>

int main() {
    int n; // 屋顶数目
    scanf("%d", &n);

    double x, y; // 坐标
    int peo;  // 每个屋顶的人数
    double time = 0.0;

    while (n--) {
        scanf("%lf %lf %d", &x, &y, &peo);

        // 计算距离，从大本营到屋顶
        double s = sqrt(x * x + y * y);

        // 从大本营到屋顶和返回大本营的时间（分钟）
        double a = (2 * s) / 50.0;

        // 每人上船的时间（分钟）
        double u = peo * 1.0;

        // 每人下船的时间（分钟）
        double d = peo * 0.5;

        // 累加当前屋顶的总时间
        time += a + u + d;
    }

    // 向上取整总时间
    printf("%d\n", (int)ceil(time));

    return 0;
}
