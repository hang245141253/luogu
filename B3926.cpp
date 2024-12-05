#include <iostream>
#include <cstring>
using namespace std;

int get_base(char *s) {
    if (strlen(s) == 1)
        return 1000;
    return s[0] == 'k' ? 1000000 : 1; // 以毫克 毫米作为基准
}

/**
 * 1 mm = 1mm
 * 1000 mm = 1m
 * 1000000mm = 1km
 * mg g kg同理
 */

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x;
        char s1[5], s2[5];
        scanf("%d", &x);
        scanf("%s", s1);
        scanf("%s", s2), scanf("%s", s2), scanf("%s", s2); // 吞掉 = 和 ？
        printf("%d %s = %d %s\n", x, s1, x * get_base(s1) / get_base(s2), s2);
    }
    return 0;
}