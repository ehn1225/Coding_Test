//다이나믹 프로그래밍 - 5 효율적인 화폐 구성
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v;
	vector<int> dp(10001, INF);
	dp[0] = 0;//0원의 경우 화폐를 아무것도 사용하지 않았을 때 만들 수 있음

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		dp[a] = 1;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	int minimun = v[0];

	for (int unit : v) {
		for (int i = unit; i < m + 1; i++) {
			dp[i] = min(dp[i], dp[i - unit] + 1);
		}
	}

	/*
	//위의 코드와 동작은 동일하나, 위의 코드가 더욱 간결함
	for (int i = minimun; i < m + 1; i++) {
		for (int unit : v) {
			if (i - unit < 0) break;
			if (dp[i - unit] != INF) {
				dp[i] = min(dp[i], dp[i - unit] + 1);
			}
		}
	}
	*/

	if (dp[m] == INF) {
		cout << -1 << '\n';
	}
	else {
		cout << dp[m] << '\n';
	}


}