#include <iostream>
using namespace std;


/*
(1,1)  -      -      -      (1,5)  
-      (2,2)  -      (2,4)  -  
-      -      (3,3)  -      -  
-      (4,2)  -      (4,4)  -  
(5,1)  -      -      -      (5,5)  
*/












int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // i==j表示左上到右下的对角线
            // i+j==N+1表示右上到左下的对角线
            if (i == j || i + j == N + 1) {
                cout << "+";
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }

    return 0;
}