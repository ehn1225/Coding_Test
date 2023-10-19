//정렬 - 4 두 배열의 원소 교체
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v[2]; //v[0] = arr a, v[1] = arr b
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			v[i].push_back(a);
		}
	}

	//a배열에서는 작은 것부터, b배열에서는 큰 것 부터 꺼내서 SWAP
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	reverse(v[1].begin(), v[1].end());

	for (int j = 0; j < k; j++) {
		if (v[0][j] < v[1][j]) {
			int tmp = v[0][j];
			v[0][j] = v[1][j];
			v[1][j] = tmp;
		}
		else {
			break;
		}		
	}

	int answer = 0;
	for (int it : v[0]) {
		answer += it;
	}

	cout << answer << '\n';

}