//Programmers 42746 : 정렬 - 가장 큰 수
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
struct DATA {
    string key;
    int idx;
};
bool cmp(DATA& a, DATA& b) {
    return a.key > b.key;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<DATA> tmp;

    for (int i = 0; i < numbers.size(); i++) {
        string a = to_string(numbers[i]);
        a = a + a + a + a;
        a = a.substr(0, 4);
        DATA temp = { a, i };
        tmp.push_back(temp);
    }

    sort(tmp.begin(), tmp.end(), cmp);

    for (int i = 0; i < tmp.size(); i++)
        answer += to_string(numbers[tmp[i].idx]);

    //0000일 경우 예외처리. stoi를 쓸경우  int 범위를 넘어가면 뻑나서 그냥 바로 내보내야함.

    if (answer[0] == '0')
        return "0";

    return answer;
}

int main() {
    vector<int> a = {0,0,0,0};

    cout << solution(a);
}