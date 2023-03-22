//Programmers 43164 : 깊이/너비 우선 탐색(DFS/BFS) - 여행경로
//Fail Case : 테스트 1번 실패, 2, 3, 4번 성공; 중간에 길이 끊겼을 경우 2번 이상 되돌아가지 못함.
#include <bits/stdc++.h>
using namespace std;

bool compare(vector<string> a, vector<string> b){
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    bool checked[10001] = {0, };
    stack <string> s;
    int tickets_size = tickets.size();
    
    //목적지를 기준으로 사전순 정렬
    sort(tickets.begin(), tickets.end(), compare);
    s.push("ICN");
    int failsafe = 0;
    bool active_fail = false;

    while(!s.empty()){
        string airport = s.top();
        s.pop();
        answer.push_back(airport);
        bool check = false;
        for(int i = 0; i < tickets_size; i++){
            if(active_fail){
                 i = failsafe + 1;
                active_fail = false;
            }
            if(tickets[i][0] == airport && !checked[i]){
                check = true;
                failsafe = i;
                checked[i] = true;
                s.push(tickets[i][1]);
                break;
            }
        }
        if(!check && (answer.size() != tickets_size+1)){
            //아무런 노드와 연결되지 않았다면 마지막 공항 제거
            answer.pop_back();
            s.push(answer.back());
            if(answer.size() != 0) answer.pop_back();
            checked[failsafe] = false;
            active_fail = true;
        }
    }
    
    return answer;
}