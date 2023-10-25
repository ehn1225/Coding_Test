//다이나믹 프로그래밍 - 32 정수 삼각형
//백준 1932
#include <bits/stdc++.h>
using namespace std;

int maps[500][500];
int dp[500][500];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> maps[i][j];
		}
	}
	dp[0][0] = maps[0][0];

	int dx[] = {-1, -1};
	int dy[] = {-1, 0};

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			int past_max = -1e9;
			for (int k = 0; k < 2; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0)
					continue;

				past_max = max(past_max, dp[nx][ny]);
			}
			dp[i][j] = past_max + maps[i][j];
		}
	}

	int result = -1e9;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[n - 1][i]);
	}

	cout << result << '\n';

}