//Programmers 43236 : 이분탐색 - 징검다리
#include <bits/stdc++.h>
#define max(x, y) {((x >= y) ? x : y)}
using namespace std;

//최소 거리를 먼저 정하고, 제거된 바위수를 체크하는 방식
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0;
    int right = distance;
    int mid = 0;
    
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    int rocks_size = rocks.size();

    while(left <= right){
        int rmStone = 0;
        int prev = 0;
        mid = (left + right) / 2; //answer이 될 값. 해당 값이 answer이 되기 위해서는 n개의 돌만 제거 되어야 함.
        for(int i = 0; i < rocks_size; i++){
            int diff = rocks[i] - prev;
            if(diff < mid)
                rmStone++;
            else
                prev = rocks[i];
        }
        if(rmStone > n) {
            right = mid - 1;
        }
        else{
            answer = max(answer, mid);    //없을 경우 오류 발생(Test Case 2, 5, 7)
            left = mid + 1;
        }
    }
    
    return answer;
}