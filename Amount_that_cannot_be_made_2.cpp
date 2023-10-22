//그리디 문제 - 4 만들 수 없는 금액
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> coin;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		coin.push_back(a);
	}
	sort(coin.begin(), coin.end());

	int target = 1;
	for (int it : coin) {
		if (target < it)
			break;
		target += it;
	}

	cout << target << '\n';

	/*
	sort(coin.begin(), coin.end());
	reverse(coin.begin(), coin.end());

	for (int cost = 1;; cost++) {
		int tmp = cost;
		for (auto it : coin) {
			if (tmp >= it && tmp > 0) {
				tmp -= it;
			}
		}
		if (tmp != 0) {
			cout << cost << '\n';
			break;
		}
	}
	*/

 }