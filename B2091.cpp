#include <iostream>
using namespace std;

int dotProduct(int *a, int *b, int n) {
    int result = 0;

    for (int i = 0; i < n; ++i) {
        result += (*a) * (*b);
        a++;
        b++;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    int a[1000], b[1000]; // 假设向量长度不超过1000

    // 读取向量a
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 读取向量b
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // 计算点积并输出
    cout << dotProduct(a, b, n) << endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// #define MAX_N 1000

// void init(int n, int arr[]) {
//     for (int i = 0; i < n; i++) 
//         cin >> arr[i];
//     return ;
// }

// int main() {
//     int a[MAX_N + 5], b[MAX_N + 5];

//     int n;
//     cin >> n;
//     init(n, a);
//     init(n, b);

//     int sum = 0;
//     for (int i = 0; i < n; i++)
//         sum += a[i] * b[i];
//     cout << sum << endl;


//     return 0;
// }