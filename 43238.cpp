//Programmers 43238 : 이분탐색 - 입국심사
#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    unsigned long long min = 1;
    unsigned long long max = times.back() * n;
    
    while(min <= max){
        long long pass = 0;
        unsigned long long middle = ((min + max) / 2);
        for(auto it : times){
            unsigned long long value = middle / it;
            pass += value;
        }
        if (n <= pass){
            answer = middle;
            max = middle - 1;
        }
        else{
            min = middle + 1;
        }
    }

    return answer;
}