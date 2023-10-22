//구현 문제 - 9 문자열 압축
//프로그래머스 60057
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
	int answer = s.length();

	for (int unit = 1; unit < (s.length() / 2) + 1; unit++) {
		string compressed;
		string prev = s.substr(0, unit);
		int cnt = 1;
		for (int j = unit; j < s.length(); j += unit) {
			if (prev == s.substr(j, unit)) {
				cnt++;
			}
			else {
				compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
				cnt = 1;
				prev = s.substr(j, unit);
			}
		}
		compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;

		answer = min(answer, (int)(compressed.length()));
	}

	return answer;
}

int main() {
	string input;
	cin >> input;

	int answer = solution(input);
	cout << answer << '\n';

}