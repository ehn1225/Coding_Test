//정렬 문제 - 26 카드 정렬하기
//백준 1715
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	priority_queue<int> pq;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(-a);
	}

	int answer = 0;
	while (pq.size() > 1) {
		int num1 = -pq.top();
		pq.pop();
		int num2 = -pq.top();
		pq.pop();
		int sum = num1 + num2;
		answer += sum;
		pq.push(-sum);
	}

	cout << answer << '\n';
}