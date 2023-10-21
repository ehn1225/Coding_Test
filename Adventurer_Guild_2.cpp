//그리디 문제 - 1 모험가 길드
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int answer = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		count++;
		if (count == v[i]) {
			answer++;
			count = 0;
		}
	}

	cout << answer << '\n';

}
