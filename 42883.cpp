//Programmers 42883 : 그리디 - 큰 수 만들기
#include <bits/stdc++.h>

using namespace std;
string solution(string number, int k) {

    int str_len = number.length();
    for(int i = 0; i < str_len-1; i++){
        if (number[i] < number[i+1]) {
            number.erase(i, 1);
            i = -1;
            k--;
        }
        if(k == 0) break;
    }
    if(k > 0) number.erase(str_len - k, k);

    return number;
}