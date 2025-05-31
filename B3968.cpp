#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student {
    int ch, math, eng;
    int total, cm_sum, cm_max;
    int index;
};

bool compare(const Student &a, const Student &b) {
    if (a.total != b.total) return a.total > b.total;
    if (a.cm_sum != b.cm_sum) return a.cm_sum > b.cm_sum;
    if (a.cm_max != b.cm_max) return a.cm_max > b.cm_max;
    return a.index < b.index;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<Student> stu(N);

    for (int i = 0; i < N; ++i) {
        cin >> stu[i].ch >> stu[i].math >> stu[i].eng;
        stu[i].total = stu[i].ch + stu[i].math + stu[i].eng;
        stu[i].cm_sum = stu[i].ch + stu[i].math;
        stu[i].cm_max = max(stu[i].ch, stu[i].math);
        stu[i].index = i;
    }
    
    sort(stu.begin(), stu.end(), compare);
    
    vector<int> rank(N);
    int curr_rank;
    Student *prev_stu = nullptr;
    
    for (int i = 0; i < N; ++i) {
        // 如果当前学生与上一个学生的成绩不同，则更新排名
        if (!prev_stu || stu[i].total != prev_stu->total ||
            stu[i].cm_sum != prev_stu->cm_sum ||
            stu[i].cm_max != prev_stu->cm_max) {
            curr_rank = i + 1;
            prev_stu = &stu[i];
        }
        rank[stu[i].index] = curr_rank;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << rank[i] << endl;
    }
    
    return 0;
}