#include <bits/stdc++.h>
using namespace std;

// 全局变量定义
int p1;               // 表示展开方式
int p2;               // 表示重复字符的次数
int p3;               // 表示是否逆序展开
int idx = 0;          // 当前处理的字符串索引
int repIdx;           // 当前重复的索引
char inputStr[300];   // 输入的字符串
char preChar;         // 减号前的字符
char nextChar;        // 减号后的字符
char curChar;         // 当前处理的字符
char tempChar;        // 临时字符变量，用于展开时的字符

int main() {
    // 读取输入：展开方式、重复字符次数、逆序标志和输入字符串
    scanf("%d%d%d%s", &p1, &p2, &p3, inputStr);

    // 遍历输入字符串
    while (inputStr[idx]) {
        preChar = inputStr[idx - 1];   // 前一个字符
        nextChar = inputStr[idx + 1];  // 后一个字符
        curChar = inputStr[idx];       // 当前字符

        // 判断是否需要展开
        if (curChar == '-' && nextChar > preChar &&
            ((preChar >= '0' && nextChar <= '9') || (preChar >= 'a' && nextChar <= 'z'))) {
            // 根据 p3 初始化 tempChar 和展开条件
            if (p3 == 1) { // 顺序展开
                tempChar = preChar + 1;
                while (tempChar < nextChar) {
                    char fillChar = tempChar;  // 填充字符

                    // 处理展开类型
                    if (p1 == 2)
                        fillChar = toupper(fillChar);  // 小写转大写
                    else if (p1 == 3)
                        fillChar = '*';  // 用星号填充

                    // 重复填充字符
                    for (repIdx = 0; repIdx < p2; repIdx++)
                        printf("%c", fillChar);

                    tempChar++;
                }
            } else { // 逆序展开
                tempChar = nextChar - 1;
                while (tempChar > preChar) {
                    char fillChar = tempChar;  // 填充字符

                    // 处理展开类型
                    if (p1 == 2)
                        fillChar = toupper(fillChar);  // 小写转大写
                    else if (p1 == 3)
                        fillChar = '*';  // 用星号填充

                    // 重复填充字符
                    for (repIdx = 0; repIdx < p2; repIdx++)
                        printf("%c", fillChar);

                    tempChar--;
                }
            }
        } else {
            // 非展开情况，直接输出字符
            printf("%c", curChar);
        }
        idx++;
    }
    return 0;
}
