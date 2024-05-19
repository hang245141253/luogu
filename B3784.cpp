#include <iostream>
#include <algorithm> // 包含算法库，用于排序
using namespace std;

const int N = 100005; // 定义一个足够大的常量N，作为数组的大小
struct son {
    int k; // k代表歌曲的编号
    int sum; // sum代表歌曲的欢乐度总和
};
struct son s[N]; // 创建一个结构体数组s，用于存储每首歌的编号和欢乐度

// 定义比较函数cmp，用于降序排序
bool cmp(son x, son y) {
    return x.sum > y.sum;
}

int main() {
    int n, m, a, b;
    // 读取输入参数：歌曲数量n、需要选出的歌曲数量m、学生数量(学号)a、她的学号b
    scanf("%d%d%d%d", &n, &m, &a, &b); 

    // 初始化结构体数组，将每首歌的编号设置为自身
    for (int i = 1; i <= n; i++)
        s[i].k = i;

    int favoritevalue = 0, favoriteid = 0; // 初始化她最喜欢的歌的快乐值和编号
    // 读取每个学生对每首歌的快乐值，并累加到对应的歌曲的欢乐度中
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= n; j++) {
            int t;
            scanf("%d", &t);
            s[j].sum += t; // 累加欢乐度
            // 如果是她听歌，更新她最喜欢的歌的信息
            if (i == b && t > favoritevalue) {
                favoritevalue = t;
                favoriteid = j;
            }
        }
    }

    // 使用sort函数和cmp比较函数对歌曲按欢乐度降序排序
    sort(s + 1, s + n + 1, cmp);

    int flag = 0; // 定义一个标志变量，用于判断她最喜欢的歌是否已经在榜单上
    // 检查她最喜欢的歌是否在选出的m首歌中
    for (int i = 1; i <= m; i++) {
        if (s[i].k == favoriteid) {
            flag = 1; // 如果在，设置flag为1
            printf("%d ", favoriteid); // 输出她最喜欢的歌的编号
            s[i].k = -1; // 将这首歌的编号设置为-1，避免重复输出
            break; // 跳出循环
        }
    }

    // 如果她最喜欢的歌已经在榜单上（flag为1），则输出剩余的歌曲编号
    if (flag == 1) {
        for (int i = 1; i <= m; i++) {
            if (s[i].k > 0) // 避免-1重复输出
                printf("%d ", s[i].k);
        }
    } else if (flag == 0) { // 如果她最喜欢的歌不在榜单上，则替换榜单最后一名的歌曲
        for (int i = 1; i < m; i++) // 输出除了最后一名之外的所有歌曲编号
            printf("%d ", s[i].k);
        printf("%d ", favoriteid); // 输出她最喜欢的歌的编号
    }

    return 0; // 程序结束
}