//정렬 문제 - 24 안테나
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	// 중간값(median)을 출력
	cout << v[(n - 1) / 2] << '\n';
}

/*
//시간초과
int main() {
	int n;
	cin >> n;
	vector<int> house;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		house.push_back(a);
	}


	sort(house.begin(), house.end());

	int min = 1e9;
	int answer = house.at(0);

	for (auto antenna_pos : house) {
		int total = 0;
		for (auto pos2 : house) {
			total += abs(antenna_pos - pos2);
		}

		if (min > total) {
			min = total;
			answer = antenna_pos;
		}
	}

	cout << answer << endl;

}*/