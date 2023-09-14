//그리디 - 큰수의 법칙
#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v;
	int n, m, k, tmp;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end()); // 입력 받은 수들 정렬하기
	int first = v[n - 1]; // 가장 큰 수
	int second = v[n - 2]; // 두 번째로 큰 수

	// 가장 큰 수가 더해지는 횟수 계산
	int cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1);

	int result = 0;
	result += cnt * first; // 가장 큰 수 더하기
	result += (m - cnt) * second; // 두 번째로 큰 수 더하기

	cout << result << endl;

	return 0;
}

/*
	vector<int> input;
	vector<int> answer;
	int n, m, k, tmp;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end()); //오름차순 정렬
	int length = input.size();
	for (int i = 0; i < m; i++) {
		int option = 1;
		int a = input[length - 1];
		for (int j = 0; j < k; j++) {
			answer.push_back(a);
		}
		answer.push_back(input[length - 2]);
	}

	int sum = 0;
	for (int i = 0; i < m; i++) {
		sum += answer.at(i);
	}

	cout << sum << endl;
*/