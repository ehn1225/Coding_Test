//Programmers 49191 : 그래프 - 순위
//Floyd WarShall 알고리즘.
//다른 선수의 승패 기록을 나에게 복사해주는 방식
#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int battle[101][101] = {0};
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
           battle[i][j] = INF;
        battle[i][i] = 0;
    } 

    for(int i = 0; i < results.size(); i++){
        battle[results[i][0]-1][results[i][1]-1] = 1;      //승자에게는 패자의 번호와 이겼다는 의미의 1
        battle[results[i][1]-1][results[i][0]-1] = -1;     //패자에게는 승자의 번호와 졌다는 의미의 -1
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(battle[i][k] == 1 && battle[k][j] == 1) {
                    battle[i][j] = 1;
                    battle[j][i] = -1;
                }
            }
        } 
    }

    for (int i = 0; i < n; i++) {
        bool check = true;
        for (int j = 0; j < n; j++) {
            if(battle[i][j] == INF){
                check = false;
                break;
            }
        }
        if(check) answer++;
    }

    return answer;
}