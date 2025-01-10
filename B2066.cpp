#include <stdio.h>
#include <math.h>

int main() {
    int n; // 屋顶数目
    scanf("%d", &n);

    double x, y; // 坐标
    int people;  // 每个屋顶的人数
    double total_time = 0.0;

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %d", &x, &y, &people);

        // 计算距离，从大本营到屋顶
        double distance = sqrt(x * x + y * y);

        // 从大本营到屋顶和返回大本营的时间（分钟）
        double travel_time = (2 * distance) / 50.0;

        // 每人上船的时间（分钟）
        double boarding_time = people * 1.0;

        // 每人下船的时间（分钟）
        double unboarding_time = people * 0.5;

        // 累加当前屋顶的总时间
        total_time += travel_time + boarding_time + unboarding_time;
    }

    // 向上取整总时间
    printf("%d\n", (int)ceil(total_time));

    return 0;
}
