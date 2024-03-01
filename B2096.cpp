#include <iostream>
using namespace std;

#define MAX_N 100000

int n;
int bucket[MAX_N + 5];
int arr[MAX_N + 5];


void init() {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return ;
}

int main() {
    cin >> n;
    init();

    int mmax = 0;
    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
        mmax = max(mmax, arr[i]);
    }
    
    for (int i = 0; i <= mmax; i++) 
        cout << bucket[i] << endl;
    return 0;
}