//정렬 문제 - 26 카드 정렬하기
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	priority_queue<int> pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(-tmp);
	}

	int answer = 0;
	while (pq.size() != 1) {
		int item1 = -pq.top();
		pq.pop();
		int item2 = -pq.top();
		pq.pop();
		int sum = item1 + item2;
		answer += sum;
		pq.push(-sum);
	}

	cout << answer << endl;

}