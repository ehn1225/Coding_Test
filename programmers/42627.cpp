#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct DATA {
    int arrive = 0;
    int process = 0;
    int idx = 0;
};

struct cmp {
    bool operator()(DATA a, DATA b) {
        return a.process > b.process;
    }
 };

int solution(vector<vector<int>> jobs) {
    int size = jobs.size();
    int answer = 0;
    int time = 0;
    sort(jobs.begin(), jobs.end());
    while(jobs.size() > 0){
        priority_queue<DATA, vector<DATA>, cmp> q;
        for (int i = 0; i < jobs.size(); i++) {
            if (time < jobs[i][0])
                break;
            if (time >= jobs[i][0]) { //현재 시간보다 먼저온 작업이 있다면 리스트에 삽입
                DATA d = {jobs[i][0], jobs[i][1], i };
                q.push(d);
            }
        }
        if (q.empty()) {
            time++;
            continue;        
        }
        else {
            DATA tmp1 = q.top();
            answer += ((time - tmp1.arrive) + tmp1.process);
            time += tmp1.process;
            jobs.erase(jobs.begin() + tmp1.idx);
        }      
    }
  
    return answer / size;
}
int main() {
    vector<vector<int>> a = { {1,9},{1,4},{1,5},{1,7},{1,3}, };
    int result = solution(a);
    cout << result;
}
