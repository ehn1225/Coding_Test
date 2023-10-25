//이진 탐색 - 29 공유기 설치
//백준 2110
#include <bits/stdc++.h>
using namespace std;

int CalcCount(vector<int> v, int d) {
	//간격을 d 이상으로 할 때 설치할 수 있는 공유기의 개수
	int count = 1;
	int pos = v[0];
	for (int house : v) {
		if (pos + d <= house) {
			count++;
			pos = house;
		}
	}

	return count;
}

int main() {
	int n, c;
	cin >> n >> c;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	//교재에서는 min_d가 1번째 원소의 값 - 0번재 원소의 값이지만, 백준에서 오류 발생함 -> 항상 최단이 아니기 때문
	int min_d = 1;
	int max_d = v.back() - v[0];

	int answer = 0;
	while (min_d <= max_d) {
		int d = (min_d + max_d) / 2;

		int count = CalcCount(v, d);

		if (count < c) {
			max_d = d - 1;
		}
		else {
			answer = d;
			min_d = d + 1;
		}
	}

	cout << answer << '\n';

}