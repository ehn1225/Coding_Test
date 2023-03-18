//Programmers 43165 : 깊이/너비 우선 탐색(DFS/BFS) - 타겟 넘버
#include <bits/stdc++.h>

using namespace std;
int v_size = 0;
int answer = 0;
vector<int> numbers2;
int target2 = 0;
void dfs(int depth,int result){
    if(depth == v_size){
        if(result == target2){
            answer++;
            cout << result << endl; 
        }
        return;
    }

    dfs(depth+1, result+numbers2[depth]);
    dfs(depth+1, result-numbers2[depth]);
}

int solution(vector<int> numbers, int target) {
    numbers2 = numbers;
    target2 = target;
    v_size = numbers.size();
    dfs(0, 0);
    return answer;
}