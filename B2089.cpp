#include <iostream>
using namespace std;

void reverseArray(int *arr, int n) {
    // 定义两个指针，一个指向数组的开头，另一个指向数组的末尾
    int *start = arr;
    int *end = arr + n - 1;

    // 交换指针指向的元素，直到两个指针相遇
    while (start < end) {
        // 交换 start 和 end 指向的元素
        int temp = *start;
        *start = *end;
        *end = temp;

        // 移动指针
        start++;
        end--;
    }
}

int main() {
    int n;
    // cout << "请输入数组元素个数：";
    cin >> n;

    int arr[100]; // 假设数组最大长度为100
    // cout << "请输入 " << n << " 个整数：";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 调用函数逆序重存放数组元素
    reverseArray(arr, n);

    // cout << "逆序重存放后的数组：";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// #define swap1(a, b) a ^= b, b ^= a, a ^= b

// int a[105];

// int main() {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     for (int i = 0; i < n / 2; i++) {
//         swap1(a[i], a[n - 1 - i]);
//     }

//     for (int i = 0; i < n; i++) {
//         // printf("a[%d] = %d\n", i, a[i]);
//         printf("%d ", a[i]);
//     }

//     return 0;
// }