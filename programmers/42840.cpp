#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct DATA {
    int score;
    int idx;
};
bool cmp(DATA& a, DATA& b) {
    return a.score > b.score;
}

vector<int> solution(vector<int> answers) {
    int person[3] = { 0,0,0 };
    int arr1[] = { 1,2,3,4,5 };
    int arr2[] = { 2,1,2,3,2,4,2,5 };
    int arr3[] = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> answer;

    for (int i = 0; i < answers.size(); i++) {
        int ans = answers[i];
        if (ans == arr1[i % 5])
            person[0]++;
        if (ans == arr2[i % 8])
            person[1]++;
        if (ans == arr3[i % 10])
            person[2]++;
    }
    vector<DATA> tmp;
    for (int i = 0; i < 3; i++) {
        DATA t = { person[i], i + 1 };
        tmp.push_back(t);
    }
    sort(tmp.begin(), tmp.end(), cmp);
    int max = tmp[0].score;
    for (int i = 0; i < 3; i++) {
        if (tmp[i].score < max)
            break;
        answer.push_back(tmp[i].idx);
    }

    return answer;
}

int main() {
    vector<int> prices = {1,2,3,4,5};
    vector<int> result;
    result = solution(prices);
    for (auto it = result.begin(); it < result.end(); it++) {
        cout << *it;
    }
}