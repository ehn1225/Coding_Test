//다이나믹 프로그래밍 문제 - 31 금광
#include <bits/stdc++.h>
using namespace std;

int testCase, n, m;
int arr[20][20];
int dp[20][20];

int main(void) {
	// 테스트 케이스(Test Case) 입력
	cin >> testCase;
	for (int tc = 0; tc < testCase; tc++) {
		// 금광 정보 입력
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		// 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = arr[i][j];
			}
		}
		// 다이나믹 프로그래밍 진행
		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				int leftUp, leftDown, left;
				// 왼쪽 위에서 오는 경우
				if (i == 0) leftUp = 0;
				else leftUp = dp[i - 1][j - 1];
				// 왼쪽 아래에서 오는 경우
				if (i == n - 1) leftDown = 0;
				else leftDown = dp[i + 1][j - 1];
				// 왼쪽에서 오는 경우
				left = dp[i][j - 1];
				dp[i][j] = dp[i][j] + max(leftUp, max(leftDown, left));
			}
		}
		int result = 0;
		for (int i = 0; i < n; i++) {
			result = max(result, dp[i][m - 1]);
		}
		cout << result << '\n';
	}
}
/*
class CASE {
public:
	int n;
	int m;
	int maps[20][21] = { 0, }; //맨 앞에 0을 넣어주기 위해서 사이즈를 21로 늘림
	CASE(int n, int m) {
		this->n = n;
		this->m = m;
	}
};

int dx[] = { 0, -1, 1};
int dy[] = {-1, -1, -1};

int main() {
	int t;
	vector<CASE> v;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		CASE tmp(a, b);
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> tmp.maps[i][j+1];
			}
		}
		v.push_back(tmp);
	}

	for (int i = 0; i < t; i++) {
		CASE tmp = v.at(i);
		int top = 0;

		for (int i = 1; i <= tmp.m; i++) { //한 열씩 계산 수행
			for (int j = 0; j < tmp.n; j++) {
				int now = tmp.maps[j][i];
				int max_value = 0;

				for (int k = 0; k < 3; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && nx < tmp.n && ny >= 0 && ny < tmp.m) {
						max_value = max(max_value, tmp.maps[nx][ny] + now);
					}
				}
				tmp.maps[j][i] = max_value;
				top = max(top, max_value);
			}
		}
		cout << top << endl;
	}
}
*/