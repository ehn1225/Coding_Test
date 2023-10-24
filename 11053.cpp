//백준 - 11053 가장 긴 증가하는 부분 수열
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		int max_value = -1e9;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				max_value = max(max_value, dp[j]);
			}
		}
		dp[i] = max(dp[i], max_value + 1);
	}

	int answer = -1e9;
	for (int i = 0; i < n; i++) {
		answer = max(answer, dp[i]);
	}

	cout << answer << '\n';
}