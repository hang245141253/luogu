#include <iostream>
using namespace std;

struct R {
    long long x1, y1, x2, y2;
} rec[2005];

bool is_Inside(int x, int y, R r) {
    return x >= r.x1 && x <= r.x2 && 
           y >= r.y1 && y <= r.y2;
}

int main() {
    int M, N;
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        cin >> rec[i].x1 >> rec[i].y1 
            >> rec[i].x2 >> rec[i].y2;
    }

    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        int cnt = 0;
        int last = -1;
        for (int j = 0; j < M; j++) {
            if (is_Inside(x, y, rec[j])) {
                cnt++;
                last = j + 1;
            }
        }

        if (cnt > 0) {
            cout << "YES " << cnt << " " << last << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}