#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    int val, idx;
} cnt[256];

char arr[25][41];

bool cmp(node x, node y) {
    return x.val > y.val;
}

inline int char_int(char ch) {
    if (ch <= '9')
        ch -= '0';
    else
        ch -= 'A' - 10;
    return ch;
}

inline int to_int(char a, char b) {
    a = char_int(a), b = char_int(b);
    return a * 16 + b;
}

int zip(int n) {
    int min = 260, ret = -1;
    for (int i = 0; i < 16; i++)
        if (min > abs(n - cnt[i].idx))
            min = abs(n - cnt[i].idx), ret = i;
    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

#define ind to_int(arr[i][j], arr[i][j + 1])
    for (int i = 0; i < n; i++)
        for (int j = 0; arr[i][j]; j += 2)
            cnt[ind].val++, cnt[ind].idx = ind;

    stable_sort(cnt, cnt + 256, cmp);

    for (int i = 0; i < 16; i++) printf("%02X", cnt[i].idx);
    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; arr[i][j]; j += 2) {
            printf("%X", zip(ind));
        }
        printf("\n");
    }

#undef ind

    return 0;
}

// #include <iostream>
// #include <algorithm>
// using namespace std;

// struct list {
// 	int value;
// 	int ind;
// };

// bool cmp(list x, list y) {
//     return x.value > y.value;
// }

// int char_to_hex(char ch) {
// 	int ret = 0;
// 	switch (ch) {
// 	case 'A':case 'B':case 'C':
// 	case 'D':case 'E':case 'F':
// 		ret = ch - 55;
// 		break;
// 	default:
// 		ret = ch - 48;
// 		break;
// 	}
// 	return ret;
// }

// int to_int(char a, char b) {
// 	int h = char_to_hex(a), l = char_to_hex(b);
// 	return h * 16 + l;
// }

// // 其他灰阶转换到最近的16种灰阶之一
// int zip(int n, list lrr[]) {
// 	int min = 256, tmp = -1;
// 	for (int i = 0; i < 16; i++) {
// 		if (min > abs(n - lrr[i].ind)) 	min = abs(n - lrr[i].ind), tmp = i;
// 	}
// 	return tmp;
// }

// int main() {
// 	int n;
// 	cin >> n;
// 	char arr[n][40] = {0};
// 	list lrr[256] = {0};

// 	// input
// 	for (int i = 0; i < n; i++) {
// 		cin >> arr[i];
// 	}

// 	// process
// 	#define index to_int(arr[i][j], arr[i][j + 1])
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; arr[i][j]; j += 2) {
// 			lrr[index].value++, lrr[index].ind = index;
// 		}
// 	}
// 	#undef index
    
// 	// sort
//     stable_sort(lrr, lrr + 256, cmp);
// 	// for (int i = 0; i < 256; i++) {
// 	// 	for (int j = 0; j < 256 - i - 1; j++) {
// 	// 		if (lrr[j].value < lrr[j + 1].value)	swap(lrr[j], lrr[j + 1]);
// 	// 	}
// 	// }

// 	// output
// 	for (int i = 0; i < 16; i++) {
// 		printf("%02X", lrr[i].ind);
// 	} putchar('\n');

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; arr[i][j]; j += 2) {
// 			int tmp = to_int(arr[i][j], arr[i][j + 1]);
// 			printf("%X", zip(tmp, lrr));
// 		}
// 		putchar('\n');
// 	}

// 	return 0;	
// } 