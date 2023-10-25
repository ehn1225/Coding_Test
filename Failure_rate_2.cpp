//정렬 문제 - 25 실패율
//프로그래머스 42889
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;

}

vector<int> solution(int N, vector<int> stages) {
    vector<int> notClear(N + 2, 0);
    for (int it : stages) {
        notClear[it]++;
    }

    int user_count = stages.size();

    vector<pair<double, int>> temp;
    for (int i = 1; i < N + 1; i++) {
        int cnt = count(stages.begin(), stages.end(), i);

        double fail = 0;
        if (user_count >= 1) {
            fail = (double)cnt / user_count;
        }
        temp.push_back({ fail, i });
        user_count -= cnt;
    }

    sort(temp.begin(), temp.end(), compare);

    vector<int> answer;
    for (auto it : temp) {
        answer.push_back(it.second);
    }

    return answer;
}