//구현 문제 - 9 문자열 압축
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
	int answer = s.size();
	// 1개 단위(step)부터 압축 단위를 늘려가며 확인
	for (int step = 1; step < s.size() / 2 + 1; step++) {
		string compressed = "";
		string prev = s.substr(0, step); // 앞에서부터 step만큼의 문자열 추출
		int cnt = 1;
		// 단위(step) 크기만큼 증가시키며 이전 문자열과 비교
		for (int j = step; j < s.size(); j += step) {
			// 이전 상태와 동일하다면 압축 횟수(count) 증가
			if (prev == s.substr(j, step)) cnt += 1;
			// 다른 문자열이 나왔다면(더 이상 압축하지 못하는 경우라면)
			else {
				compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
				prev = s.substr(j, step); // 다시 상태 초기화
				cnt = 1;
			}
		}
		// 남아있는 문자열에 대해서 처리
		compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
		// 만들어지는 압축 문자열이 가장 짧은 것이 정답
		answer = min(answer, (int)compressed.size());
	}
	return answer;
}

/*
int main() {
	string input;
	int length = 0, min1 = 1000;

	cin >> input;
	length = input.size();

	for (int w_size = 1; w_size < (length / 2) + 1; w_size++) {
		int count = 1;
		string tmpStr;
		string before_window = input.substr(0, w_size);
		for (int i = w_size; i < length; i += w_size) {
			string now_window = input.substr(i, w_size);
			if (before_window.compare(now_window) == 0) {
				count++;
			}
			else {
				//새로운 반복의 시작이니 저장
				if (count >= 2) {
					tmpStr += to_string(count);
					tmpStr += before_window;
				}
				else {
					tmpStr += before_window;
				}
				before_window = now_window;
				count = 1;
			}
		}
		if (count >= 2) {
			tmpStr += to_string(count);
			tmpStr += before_window;
		}
		else {
			tmpStr += before_window;
		}
		min1 = min(min1, (int)tmpStr.size());

	}

	cout << min1 << endl;

}
*/