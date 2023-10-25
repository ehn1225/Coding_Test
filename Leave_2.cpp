//다이나믹 프로그래밍 - 33 퇴사
//백준 14501
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> t;
	vector<int> p;
	vector<int> dp(n + 1, 0);
	//dp[i] = i번째 날부터 마지막 날까지 낼 수 있는 최대 이익
	//뒤쪽부터 매 상담에 대하여 ‘현재 상담 일자의 이윤(p[i]) + 현재 상담을 마친 일자부터의 최대 이윤(dp[t[i] + i]])’을 계산하면 된다
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		t.push_back(a);
		p.push_back(b);
	}

	int answer = 0;
	int max_value = 0;
	for (int i = n - 1; i > -1; i--) {
		int time = t[i] + i;
		if (time <= n) {
			dp[i] = max(max_value, dp[time] + p[i]);
			max_value = dp[i];
		}
		else {
			dp[i] = max_value;
		}
	}

	cout << max_value << '\n';


}