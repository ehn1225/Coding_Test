//Programmers 43162 : 깊이/너비 우선 탐색(DFS/BFS) - 네트워크
#include <bits/stdc++.h>

using namespace std;
bool checked[201] = {0, };
int result = 0;
int computer_size = 0;
int checkValidation(){
    bool tmp = true;
    for(int i =0; i < computer_size; i++){
        tmp = (tmp && checked[i]);
        if(tmp == false)
            return i;
    }
    return 0;
}

void dfs(int start, vector<vector<int>> computers){
    result++;
    stack<int> s;
    s.push(start);
    while(!s.empty()){
        int host = s.top();
        s.pop();
        checked[host] = true;
        for(int i = 0; i < computer_size; i++){
            if(computers[host][i] == 1 && checked[i] == false)
                s.push(i);
        }
    }
    
}
int solution(int n, vector<vector<int>> computers) {
    computer_size = computers.size();
    dfs(0, computers);
    int rst = 0;
    while((rst = checkValidation()) != 0)
        dfs(rst, computers);
    
    return result;
}