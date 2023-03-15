//Programmers 42578 : 해시 - 위장 
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for (int i = 0; i < clothes.size(); i++) {
        if (m.find(clothes[i][1]) != m.end()) {
            m[clothes[i][1]]++;
        }
        else {
            m.insert(make_pair(clothes[i][1], 1));
        }
    }
    int result = 1;
    for (auto it = m.begin(); it != m.end(); it++) {
        result *= (it->second + 1);
    }
    result = result - 1;
    return result;

}