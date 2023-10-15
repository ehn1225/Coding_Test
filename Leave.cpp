// 다이나믹 프로그래밍 - 33 퇴사
#include <bits/stdc++.h>
using namespace std;

vector<int> t; // 각 상담을 완료하는데 걸리는 기간
vector<int> p; // 각 상담을 완료했을 때 받을 수 있는 금액
int dp[16]; // 다이나믹 프로그래밍을 위한 1차원 DP 테이블 초기화

int main(void) {
	int n; // 전체 상담 개수
	int maxValue = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		t.push_back(x);
		p.push_back(y);
	}

	// 리스트를 뒤에서부터 거꾸로 확인
	for (int i = n - 1; i >= 0; i--) {
		int time = t[i] + i;
		// 상담이 기간 안에 끝나는 경우
		if (time <= n) {
			// 점화식에 맞게, 현재까지의 최고 이익 계산
			dp[i] = max(p[i] + dp[time], maxValue);
			maxValue = dp[i];
		}
		// 상담이 기간을 벗어나는 경우
		else dp[i] = maxValue;
	}

	cout << maxValue << '\n';
}

/*
* //샘플 문제에 대해서는 성공하나, 백준으로 돌리면 틀림.
int getPrevMax(int* arr, int idx) {
	int value = 0;
	for (int i = idx; i > 0; i--) {
		value = max(value, arr[i]);
		if (value != 0) break;
	}
	return value;

}
int main() {
	int n;
	cin >> n;
	int result[16] = { 0, };
	int max_result = 0;
	int prev_max = 0;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;

		if (i + a > n + 1) {
			continue;
		}

		result[i+a] = max(result[i + a], b + getPrevMax(result, i));
		max_result = max(max_result, result[i + a]);
	}

	cout << max_result << endl;
	
}
*/