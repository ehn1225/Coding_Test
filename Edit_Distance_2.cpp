//다이나믹 프로그래밍 - 36 편집 거리
#include <bits/stdc++.h>
using namespace std;

int main() {
	string from;
	string to;
	cin >> from >> to;

	vector<vector<int>> dp(from.length() + 1, vector<int>(to.length() + 1, 0));

	for (int i = 0; i < to.length() + 1; i++) {
		dp[0][i] = i;
	}

	for (int i = 0; i < from.length() + 1; i++) {
		dp[i][0] = i;
	}

	//dp에 넣을 때 1씩 더해서 넣을 것
	for (int i = 0; i < from.length(); i++) {
		for (int j = 0; j < to.length(); j++) {
			if (from[i] == to[j]) {
				dp[i + 1][j + 1] = dp[i][j];
			}
			else {
				dp[i + 1][j + 1] = min(dp[i][j+1], min(dp[i][j], dp[i+1][j])) + 1;
			}
		}
	}

	cout << dp[from.length()][to.length()] << '\n';


}