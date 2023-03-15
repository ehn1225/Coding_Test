//Programmers 42883 : 그리디 - 큰 수 만들기
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int size_r = 0;
char pArr[1000000] = {};
bool check[1000000] = {};
string input = "";
int input_size = 0;

vector<string> tmp;

void permutation(int depth) {
    if (depth == size_r) {
        tmp.push_back(pArr);
        return;
    }

    for (int i = 0; i < input_size; i++) {
        if (!check[i]) {
            check[i] = true;
            pArr[depth] = input[i];
            permutation(depth + 1);
            check[i] = false;
        }
    }
}


string solution(string number, int k) {
    string answer = "";
    input = number;
    input_size = number.length();
    size_r = input_size - k;

    permutation(0);

    sort(tmp.begin(), tmp.end());
    answer = tmp[tmp.size() - 1];


    return answer;
}

int main() {

    cout << solution("1231234", 3);
}