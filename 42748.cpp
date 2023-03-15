//Programmers 42748 : 정렬 - K번째수
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;

    for (int i = 0; i < commands.size(); i++) {
        tmp.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(tmp.begin(), tmp.end());
        int pos = commands[i][2]-1;
        answer.push_back(tmp[pos]);
        tmp.clear();
    }

    return answer;
}

int main() {
    vector<int> array = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3},{4,4,1},{1,7,3} };
    vector <int>result;

    result = solution(array, commands);

    for (auto it = result.begin(); it < result.end(); it++)
        cout << *it;

}