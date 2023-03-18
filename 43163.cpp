//Programmers 43163 : 깊이/너비 우선 탐색(DFS/BFS) - 단어 변환
#include <bits/stdc++.h>
using namespace std;

int CountDiffChar(string a, string b){
    int result = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i])
            result++;
    }
    return result;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int visited[51] = {0, };
    
    //반환 가능 여부 사전 확인
    auto it = find(words.begin(), words.end(), target);
    if(it == words.end())
        return 0;
    
    int words_size = words.size();
    queue <pair<string, int>> q;
    q.emplace(begin, 0);
    while(!q.empty()){
        auto [word, count] = q.front();
        if(word == target)
            return count;
        q.pop();
        for(int i = 0; i < words_size; i++){
            if(CountDiffChar(word, words[i]) == 1 && !visited[i]){
                q.emplace(words[i], count+1);
                visited[i] = true;
            }
        }
    }
    
    return answer;
}