//그리디 문제 - 무지의 먹방 라이브
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    vector<pair<int, int>> foods;
    int n = food_times.size();

    for (int i = 0; i < n; i++) {
        foods.push_back({ food_times[i], i + 1 });
    }

    sort(foods.begin(), foods.end());

    int prev = 0;
    vector<pair<int, int>>::iterator it;
    for (it = foods.begin(); it != foods.end(); it++, n--) {
        long long spentTime = (long long)(it->first - prev) * n;    //높이가 동일하다면 넘어가기 위해 prev 사용
        
        if (spentTime == 0)
            continue;
        if (spentTime < k) {
            k -= spentTime;
            prev = it->first;
        }
        else {
            k %= n;
            sort(it, foods.end(), compare);
            return (it + k)->second;
        }
    
    }
    return -1;
}

int main() {
    vector<int> food_times = { 3, 1, 2 };
    int k = 5;
    int answer = solution(food_times, k);
    cout << answer << '\n';

}