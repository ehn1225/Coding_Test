//정렬 문제 - 24 안테나
//백준 18310
//정렬 후 중간값을 찾는 문제
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> houses;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		houses.push_back(a);
	}

	sort(houses.begin(), houses.end());

	cout << houses[(n - 1) / 2] << '\n';

}