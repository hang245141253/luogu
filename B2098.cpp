#include <iostream>
using namespace std;

int arr[20005];  
bool bu[105];

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (!bu[num]) {
            arr[cnt++] = num;
            bu[num] = true;
        }
    }
    for (int i = 0; i < cnt; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}