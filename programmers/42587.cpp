#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct DATA {
    int priority = 0;;
    int index = 0;
};

bool Find_first(queue<DATA> q, int a) {
    while (!q.empty()) {
        DATA tmp = q.front();
        if (tmp.priority > a)
            return true;
        q.pop();
    }
    return false;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<DATA> result;
    queue<DATA> q;
    for (int i = 0; i < priorities.size(); i++) {
        DATA tmp;
        tmp.priority = priorities[i];
        tmp.index = i;
        q.push(tmp);
    }


    while (!q.empty()) {
        DATA tmp = q.front();
        if (Find_first(q, tmp.priority)) {
            q.pop();
            q.push(tmp);
            continue;
        }
        else {
            q.pop();
            result.push(tmp);
        }
    }
    int a = result.size();
    for (int i = 0; i < a; i++) {
        DATA tmp = result.front();
        if (location == tmp.index)
            return i+1;

        result.pop();
    }

}

int main(){
    vector<int>a = {1,1,9,1,1,1};
    int b = 0;
    cout << solution(a, b);

}