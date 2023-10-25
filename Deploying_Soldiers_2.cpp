//다이나믹 프로그래밍 - 34 병사 배치하기
//백준 18353
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	//내림차순 -> 오름차순으로 변경
	reverse(v.begin(), v.end());

	//LIS - 가장 긴 증가하는 순열 알고리즘 사용
	vector<int> dp(n + 1, 0);
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int now = v[i];
		int max_value = 0;
		for (int j = 0; j < i; j++) {
			if(v[j] < now){
				max_value = max(max_value, dp[j]);
			}
		}
		dp[i] = max_value + 1;
		answer = max(answer, dp[i]);
	}

	answer = n - answer;
	cout << answer << '\n';

}