//Programmers 42626 : 힙 - 더 맵게
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    int tmp = 0;
    while (!pq.empty()&&(tmp = pq.top()) < K) {
        pq.pop();
        if (pq.empty())
            return -1;
        int sec = pq.top();
        pq.pop();
        pq.push(tmp + sec * 2);
        answer++;
    }

    return answer;
}
int main() {
    vector<int> a = {1,1,1,3};
    int b = 0;
    b = solution(a,20);
    cout << "result : " << b;
}