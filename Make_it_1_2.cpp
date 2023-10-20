//다이나믹 프로그래밍 - 2 1로 만들기
#include <bits/stdc++.h>
using namespace std;
int dp[30001] = { 0, };

int FindAnswer(int x) {
	//Top-Down
	//입력값 26 기준으로, 메모이제이션 도입한 결과 FindAnswer()의 호출 횟수 : 556 -> 52로 감소
	if (x < 2)
		return 0;

	if (dp[x] != 0)
		return dp[x];

	int mininum = x - 1;
	if (x % 5 == 0) {
		mininum = min(mininum, FindAnswer(x / 5) + 1);
	}
	if (x % 3 == 0) {
		mininum = min(mininum, FindAnswer(x / 3) + 1);
	}
	if (x % 2 == 0) {
		mininum = min(mininum, FindAnswer(x / 2) + 1);
	}
	
	mininum = min(mininum, FindAnswer(x - 1) + 1);
	dp[x] = mininum;
	return dp[x];

}

int FindAnswer2(int x) {
	//Bottom_Up
	for (int i = 2; i < x + 1; i++) {
		dp[i] = dp[i - 1] + 1;
		
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 5 == 0) {
			dp[i] = min(dp[i], dp[i / 5] + 1);
		}
	}

	return dp[x];
}

int main() {
	int x;
	cin >> x;

	int answer = FindAnswer(x);
	cout << answer << '\n';
	answer = FindAnswer2(x);
	cout << answer << '\n';

}