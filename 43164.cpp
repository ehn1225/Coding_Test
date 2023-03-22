//Programmers 43164 : 깊이/너비 우선 탐색(DFS/BFS) - 여행경로
#include <bits/stdc++.h>
using namespace std;
vector<string> result;
bool visited[10001] = {0};

bool DFS(string from, vector<vector<string>> tickets, int depth){
    int tickets_size = tickets.size();
    if(depth == tickets_size){      //종착지에 도착했다면
        return true;
    }
    for(int i = 0; i < tickets_size; i++){
        if(tickets[i][0] == from && !visited[i]){       //해당 공항에서 출발하는 항공권이 있을 때
            visited[i] = true;
            result.push_back(tickets[i][1]);
            bool isValid = DFS(tickets[i][1], tickets, depth+1);        //해당 항공권의 목적지로 DFS 수행
            if(isValid) return true;
            visited[i] = false;
        }
    }
    result.pop_back();      //방문했을 때, 진행가능한 항공권이 없다면
    return false;
}      

vector<string> solution(vector<vector<string>> tickets) {    
    sort(tickets.begin(), tickets.end());
    
    result.push_back("ICN");
    DFS("ICN", tickets, 0);
    
    return result;
}