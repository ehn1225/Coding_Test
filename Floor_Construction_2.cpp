//다이나믹 프로그래밍 - 4 바닥 공사
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[1001] = { 0, };
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i < n + 1; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 796796;
	}

	cout << dp[n] << '\n';

}