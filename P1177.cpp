#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int arr[N];

void bubble(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void select(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) 
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insert(int* arr, int n) {
    for (int i = 1, j; i < n; i++) {
        int key = arr[i];  // 记录选择的数
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            // 向后移动元素
            arr[j + 1] = arr[j];
        }
        // 插入
        arr[j + 1] = key;
    }
}

int main() {
    int n;    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // select(arr, n);
    // bubble(arr, n);
    // insert(arr, n);

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}