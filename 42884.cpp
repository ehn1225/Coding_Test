//Programmers 42884 : 그리디 - 단속카메라
#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), comp);
    
    int camera = -30001;
    int r_size = routes.size();
    for(int i = 0; i < r_size; i++){
        int in = routes[i][0];
        int out = routes[i][1];
        if(in > camera){
            camera = out;
            answer++;
        }
    }
    return answer;
}