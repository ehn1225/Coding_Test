//그리디 문제 - 4 만들 수 없는 금액
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> v;
	cin >> n;

	int total = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int target = 1;
	for (auto it : v) {
		if (target < it)
			break;
		target += it;
	}

	cout << target << endl;
}

/*
bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n;
	vector<int> v;
	cin >> n;

	int total = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		total += a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), compare); //내림차순 정렬

	int result = 0;
	for (int i = 1; i <= total; i++) {
		int cost = i;
		for (auto it : v) {
			if (cost >= it) {
				cost -= it;
			}
			if (cost == 0) break;
		}
		if (cost != 0) {
			result = i;
			break;
		}
	}
	cout << result << endl;
}
*/