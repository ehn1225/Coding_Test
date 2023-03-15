//Programmers 42885 : 그리디 - 구명보트
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    //일단 몸무게를 기준으로 내림차순 정렬
    //배열의 시작을 순환하면서 배열에 삽입
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<>());
    int bpos = 0;
    int person_count = people.size();
    int epos = person_count - 1;

    while(person_count > 0){
        //제일 무거운 사람을 선택하고, 한 배에 같이 탈 사람을 찾음. 없으면 혼자 탐.
        int weight = people[bpos++];
        person_count--;
        if(weight + people[epos] <= limit){
            epos--;
            person_count--;
        }
        answer++;
    }
    return answer;
}