#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int, vector<int>, greater<int>> q_g; //작은게 튀어나옴
    priority_queue<int, vector<int>> q_i;               //큰게 튀어나옴
    vector<int> answer = {0,0};

    int ist = 0;
    int del = 0;

    for (int i = 0; i < operations.size(); i++) {
        if (ist == del) {
            while (!q_i.empty()) {
                q_i.pop();
                q_g.pop();

            }
        }
        string tmp = operations[i];
        char value_c[10];
        memset(value_c, 0, 10);
        char operation = tmp[0];
        for (int j = 2; j < tmp.length(); j++)
            value_c[j-2] = tmp[j];
        value_c[tmp.length()-2] = '\0';
        int value = stoi(value_c);

        if (operation == 'I') {
            q_g.push(value);
            q_i.push(value);
            ist++;
        }
        else {
            if (ist == del) {
                continue;
            }
            del++;
            if (value > 0)
                q_i.pop();
            else
                q_g.pop();
        }
    }
    if (ist == del) {
        answer = { 0,0 };
    }
    else {
        answer = {q_i.top(), q_g.top()};
    }

    return answer;
}

int main() {
    vector<string> prices = { "I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6" };
    vector<int> result;
    result = solution(prices);
    for (auto it = result.begin(); it < result.end();it++) {
        cout << *it;
    }
}