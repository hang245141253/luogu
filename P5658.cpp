#include <iostream>
#include <cstring>
using namespace std;

/*
() 是合法括号串。
如果 A 是合法括号串，则 (A) 是合法括号串。   两个合法子串
如果 A，B 是合法括号串，则 AB 是合法括号串。 三个合法字串

()() 是三个合法括号
(()) 是两个合法括号
((1))(2) 是四个合法括号 (1)、((1))、(2)、((1))(2)一共四个
()()()是六个合法括号

*/


#define MAX_N 500005
#define MAX_M 500005

int Head[MAX_N], Edge[MAX_M], Next[MAX_M], Fa[MAX_N], cnt;
char str[MAX_N]; 
int s[MAX_N], top;
long long lst[MAX_N], sum[MAX_N], ans;


// 链式前向星，本质是静态链表
void add_Edge(int u, int v) {         
    Edge[cnt] = v;// 节点cnt的data域存值
    Next[cnt] = Head[u];// 节点cnt的指针域指向head[u]的指向
    Head[u] = cnt++;// head[u]指向cnt,完成头插，并且cnt++移动到空位
    // Head[u]和cnt都属于指针
}


void dfs(int x) {
    int flag = 0;
    if (str[x] == '(') {
        s[++top] = x; // top = 0不存，作为空栈判断的标志，只存左括号
    } else {
        if (top) { // 读到')'且栈不为空时，一定可以有左括号进行抵消
            flag = s[top];
            // 假设这个前括号的前1位同样有一个已经匹配了的后括号，那么我们势必可以把当前的匹配和之前的匹配序列合并，当前的这个后括号的贡献值，其实就等于前面那个后括号的贡献值+1
            lst[x] = lst[Fa[flag]] + 1;
            top--;
        }
    }

    sum[x] = sum[Fa[x]] + lst[x];

    for (int i = Head[x]; i != -1; i = Next[i])     dfs(Edge[i]);

    if (flag) s[++top] = flag;
    else if (top) --top;
}

int main() {
    memset(Head, -1, sizeof(Head));
    int n;
    scanf("%d ", &n);
    scanf("%s", str + 1);
    // printf("%s", str);

    // 输入树的边，并构建树
    for(int i = 2; i <= n; i++) {
        int f;
        scanf("%d", &f);    // f是i的父节点
        add_Edge(f, i);     // 建立父子关系
        Fa[i] = f;          // 记录父节点
    }
    dfs(1);
    for(int i = 1; i <= n; i ++) {
        ans ^= sum[i] * i;
        // printf("%lld * %d = %lld \n", sum[i], i, sum[i] * i);
    }
	printf("%lld\n", ans);


    for (int i = 1; i <= n; i++) {
        printf("%lld ", lst[i]);
    } printf("\n");

    for (int i = 1; i <= n; i++) {
        printf("%lld ", sum[i]);
    } printf("\n");


    return 0;
}