//DFS/BFS - 18 괄호변환
#include <bits/stdc++.h>
using namespace std;

int balancedIndex(string p) {
    int count = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            count++;
        else
            count--;
        if (count == 0) return i;
    }
    return -1;
}

bool checkProper(string p) {
    int count = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            count++;
        else {
            if (count == 0)
                return false;
            count--;
        }
    }
    return true;
}

string solution(string p) {
    string answer = "";
    if (p == "") return answer;

    int index = balancedIndex(p);
    string u = p.substr(0, index + 1);
    string v = p.substr(index + 1);

    if (checkProper(u))
        answer = u + solution(v);
    else {
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1, u.size() - 2);
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        answer += u;
    }

    return answer;
}

int main() {
    string tmp = "()))((()";
    cout << solution(tmp);

}