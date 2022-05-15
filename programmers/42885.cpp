#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    queue <int> q;
    for (auto it = people.begin(); it != people.end(); it++)
        q.push(*it);
    int load = 0;
    int people_count = 0;
    while (!q.empty()) {
        if (load + q.front() <= limit && people_count < 2) {
            load += q.front();
            q.pop();
            people_count++;
        }
        else {
            load = 0;
            people_count = 0;
            answer++;        
        }    
    }
    if (load > 0) {
        answer++;
    }

    return answer;
}

int main() {
    cout << solution({20,20,20,20,20,20}, 100);


}