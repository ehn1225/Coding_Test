//다이나믹 프로그래밍 - 3 개미 전사
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int dp[100] = { 0, };
	dp[0] = 0;
	dp[1] = max(v[0], v[1]);
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i-1], dp[i - 2] + v[i]);
	}

	cout << dp[n-1] << '\n';
}