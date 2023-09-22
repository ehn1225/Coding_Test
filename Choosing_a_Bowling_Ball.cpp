//그리디 문제 - 5 볼링공 고르기
#include <bits/stdc++.h>
using namespace std;

int main() {
	int w[11] = { 0, };
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		w[tmp]++;
	}

	int result = 0;
	for (int i = 1; i < m + 1; i++) {
		n -= w[i];
		result += w[i] * n;
	}

	cout << result << endl;
}

/*
	int result = 0;
	int w[1001] = { 0, };
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		w[i] = tmp;
	}

	for (int i = 1; i <= n; i++) {
		int w_now = w[i];
		for (int j = i + 1; j <= n; j++) {
			if (w_now != w[j])
				result++;
		}
	}

	cout << result << endl;
*/