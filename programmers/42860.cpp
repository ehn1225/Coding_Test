#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.length();
    int move = name.length() - 1;

    for(int i = 0; i < length; i++){
        int diff_idx = 0; //각 자리에서 문자 이동간 조작횟수 카운트
        diff_idx = name[i] - 'A';
        if (diff_idx > 13)
            diff_idx = 26 - diff_idx;
        cout << diff_idx << endl;
        answer += diff_idx;

        int index = i + 1;
        while (index < length && name[index] == 'A')
            index++;
        //밑에 부분은 이해못함.
        move = min(move, i * 2 + length - index);
        move = min(move, (length-index)*2 + i);

    }
    return answer + move;

    /*
     int shortest = 0;
    for (int i = 1; i < 20; i++) {
        if (arr[i] == 1)
            shortest = i;
    
    }
    int tmp = 0;
    for (int i = 19; i > 0; i--) {
        if (arr[i] == 1)
            tmp = i;
    }
    tmp = (name.length() - tmp);
    if (shortest > tmp)
            shortest = tmp;


    return answer + shortest;
    */

}

int  main() {
   cout <<  solution("ABAAAAAAAAABB");

}