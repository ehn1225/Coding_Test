//Programmers 42861 : 그리디 - 섬 연결하기
#include <bits/stdc++.h>

using namespace std;
int arr[101][101] = {0, }; 
int connect[101][101] = {0, }; 

bool check_conn(int n){
    stack<int> s;
    bool check[101] = {0, };
    s.push(0);
    while(!s.empty()){
        int node = s.top();
        s.pop();
        check[node] = true;
        for(int i = 0; i < n; i++){
            if(connect[node][i] == 1 && !check[i]){
                s.push(i);
            }
        }
    }
    bool result = true;
    for(int i = 0; i < n; i++){
        result = (result && check[i]);
        if(result == false) break;
    }
    
    return result;
}

bool check_line(int a, int b, int n){
    stack<int> s;
    bool check[101] = {0, };
    s.push(a);
    while(!s.empty()){
        int node = s.top();
        check[node] = true;
        s.pop();
        if(node == b) return true;
        for(int i = 0; i < n; i++){
            if(i == a) continue;
            if(connect[node][i] == 1 && !check[i]){
                s.push(i);
            }
        }
    }
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //각 섬간의 연결 비용 저장
    for(auto it : costs){
        int p1 = it[0];
        int p2 = it[1];
        int cost = it[2];
        arr[p1][p2] = cost;
        arr[p2][p1] = cost;
    }
    
    int cost = 1;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == cost && connect[i][j] == 0){
                //cycle이 생기는지 확인
                if(check_line(i, j, n))
                    continue;
                //두 섬을 연결
                connect[i][j] = 1;
                connect[j][i] = 1;
                //cout << "conn : " << i << " " << j << " " << cost << endl;
                answer += cost;
            }
            //모든 섬이 연결될 경우 반복문 종료
            if(check_conn(n)){
                i = n;
                break;
            }
        }
        if(i == n-1){
            cost++;
            i = -1;
        }
    }
    
    
    return answer;
}