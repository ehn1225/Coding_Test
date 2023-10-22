//그리디 문제 - 5 볼링공 고르기
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	//각 무게별 공의 개수 저장
	vector<int> array(m+1, 0);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		array[a]++;
	}

	int answer = 0;
	for (int i = 1; i < m + 1; i++) {
		n -= array[i];
		answer += array[i] * n;
	}


	/*
	vector<int> balls(n);
	for (int i = 0; i < n; i++) {
		cin >> balls[i];
	}

	sort(balls.begin(), balls.end());

	int answer = 0;
	for (int a = 0; a < balls.size(); a++) {
		for (int b = a + 1; b < balls.size(); b++) {
			if (balls[a] == balls[b])
				continue;
			answer++;
		}
	}
	*/
	cout << answer << '\n';
}