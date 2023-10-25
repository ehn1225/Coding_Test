//다이나믹 프로그래밍 - 31 금광
#include <bits/stdc++.h>
using namespace std;
int maps[20][20];
int dp[20][20];

int dx[] = { -1, 0, 1 };

int main() {
	int t;
	cin >> t;

	for (int c = 0; c < t; c++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> maps[i][j];
			}
			dp[i][0] = maps[i][0];
		}

		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				int max_past = -1e9;
				for (int k = 0; k < 3; k++) {
					int x = i + dx[k];
					int y = j - 1;
					if (x < 0 || x >= n || y < 0 || y >= m)
						continue;

					max_past = max(max_past, dp[x][y]);
				}

				dp[i][j] = max_past + maps[i][j];
			}
		}

		int answer = -1e9;
		for (int i = 0; i < n; i++) {
			answer = max(answer, dp[i][m - 1]);
		}

		cout << answer << '\n';

	}

}