//DFS/BFS - 18 괄호변환
//프로그래머스 60058
#include <bits/stdc++.h>
using namespace std;

int BalancedString(string tmp) {
	int open = 0;
	int close = 0;

	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == '(') {
			open++;
		}
		else {
			close++;
		}
		if (open == close) {
			return i + 1;
		}
	}
	return tmp.length();
}

bool RightString(string tmp) {
	int top = 0;
	for (int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == '(') {
			top++;
		}
		else {
			top--;
		}
		if (top < 0)
			return false;
	}
	if (top == 0)
		return true;
	else
		return false;
}


string solution(string p) {
	if (p == "") return "";
	int pos = BalancedString(p);
	string u = p.substr(0, pos);
	string v = p.substr(pos, p.length() - pos);

	if (RightString(u) == true) {
		return u + solution(v);
	}
	else {
		string result = "(";
		result += solution(v);
		result += ")";
		u = u.substr(1, u.length() - 2);
		for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(') {
				u[i] = ')';
			}
			else {
				u[i] = '(';
			}
		}

		return result + u;

	}
}
int main() {
	string sample1 = "(()())()";
	string sample2 = ")(";
	string sample3 = "()))((()";

	cout << solution(sample1) << '\n';
	cout << solution(sample2) << '\n';
	cout << solution(sample3) << '\n';

}