#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1000
int a[MAX_N + 5], b[MAX_N + 5];

// 不对原数组进行排序，对下标数组进行排序
int ind[MAX_N + 5];

// BigInt 公有继承动态数组类
class BigInt : public vector<int> { // 存大整数的时候倒着存
public:
    BigInt(int x) {
        this->push_back(x);
        process_digit(); // 处理进位
        return ;
    }

    // test
    void print() {
        for (int i = size() - 1; i >= 0; i--) {
            // cout << at(i);   // 会检查边界，越界会抛出异常
            cout << (*this)[i]; // 不查边界，越界是UB，很可能导致RE
            /*this可以：
            区分同名成员和参数
            通过当前对象调用自身
            支持链式调用*/
        }   cout << endl;
    }

    // 1234 -> [4, 3, 2, 1]
    void process_digit() {
        for (int i = 0; i < size(); i++) {
            if (at(i) < 10) continue;
            if (i + 1 == size())    this->push_back(0); // 已经是最高位了还产生进位，需要扩容
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        // 去除前导0 (至少保留1位数，不能为空。只有1位数时肯定没前导0)
        while (size() > 1 && at(size() - 1) == 0)   this->pop_back();
    }

    void operator*=(int x) {
        for (auto &i : (*this))     i *= x;
        // for (int i = 0; i < size(); i++)    at(i) *= x;
        process_digit();
    }

    bool operator>(const BigInt &ans) {
        // 长度不等，更长的最大
        if (size() != ans.size())   return size() > ans.size();
        // 长度相等，逐位比较（倒着从低位遍历）
        for (int i = size() - 1; i >= 0; i--) {
            if (at(i) != ans[i])    return at(i) > ans[i];
        }
        return false;   // 相等返回false
    }

    // 类内运算符重载：左操作数隐含为当前对象（即通过 this 指针引用）。
    BigInt operator/(int x) {
        /*模拟除法竖式
        比如:   0 4 1 0
              /---------  
           9 /  3 6 9 2
        mod     0
            ------------
                3 
        mod     3 6
            ------------
                  0 
        mod         9
                --------
        mod           2
        编码时分成两个步骤处理：
            第一步：先算出一个带前导0的商
            第二步：去掉前导0
        */
        BigInt ret(*this); // this指针引用的是左操作数
        int mod = 0;
        for (int i = size() - 1; i >= 0; i--) { // 从高位遍历到低位
            mod = mod * 10 + at(i);
            ret[i] = mod / x;
            mod %= x;
        }
        ret.process_digit();    // 处理前导0
        return ret;
    }

    // 不是类的成员函数，但可以访问类的私有和保护成员。
    // 通过 friend 声明，允许全局函数访问类的内部细节。
    // 因为普通函数是不能访问类内非公共权限的成员
    // friend解决了这个问题
    // 本质是一个可以访问该类内成员的函数
    friend ostream &operator<<(ostream &out, const BigInt &a) {
        for (int i = a.size() - 1; i >= 0; i--) out << a[i];
        return out;
    }
};

// ostream类外运算符重载，因为ostream的左操作数的类型是ostream。
// 而类内运算符重载的话，该类的对象默认为左操作数。
// ostream &operator<<(ostream &out, const BigInt &a) {
//     for (int i = a.size() - 1; i >= 0; i--) out << a[i];
//     return out;
// }

// 比较函数b
bool compare(int i, int j) {
    return a[i] * b[i] < a[j] * b[j];
}

void test() {
    BigInt a(2);     // 直接调用构造函数初始化a，中间无临时对象和拷贝，效率高
    for (int i = 0; i < 64; i++)    a *= 2;
    BigInt b = a / 2;    // 拷贝初始化，先创建临时对象，然后通过拷贝构造函数将其赋值给b，效率低
    a.print();
    b.print();
    cout << a.capacity() << " " << (a < b) << endl;
    cout << a << " " << b << endl;
}

int main() {
    // test(); return 0;

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {  // n + 1个输入 0号位置是国王
        cin >> a[i] >> b[i];
        ind[i] = i;
    }
    // 对所有大臣排序，需要+1
    sort(ind + 1, ind + n + 1, compare);

    BigInt p = a[0], ans = 0, tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp = p / b[ind[i]];
        if (tmp > ans)
            ans = tmp;
        p *= a[ind[i]];
    }
    cout << ans << endl;
    // ans.print(); 
    return 0;
}
