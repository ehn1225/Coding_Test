//다이나믹 프로그래밍 - 32 정수 삼각형
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[500][500]; // 다이나믹 프로그래밍을 위한 DP 테이블 초기화

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> dp[i][j];
        }
    }
    // 다이나믹 프로그래밍으로 2번째 줄부터 내려가면서 확인
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int upLeft, up;
            // 왼쪽 위에서 내려오는 경우
            if (j == 0) upLeft = 0;
            else upLeft = dp[i - 1][j - 1];
            // 바로 위에서 내려오는 경우
            if (j == i) up = 0;
            else up = dp[i - 1][j];
            // 최대 합을 저장
            dp[i][j] = dp[i][j] + max(upLeft, up);
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[n - 1][i]);
    }
    cout << result << '\n';
}

/*
int arr[500][500] = { 0, };
int dp[500][500] = { 0, };

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			//왼쪽 위의 것과 바로 위의 것 중 큰 값을 선택하고, 해당 값에 현재 값을 더한 것이 최댓값이다.
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[n - 1][i]);
	}

	cout << result << endl;

}
*/