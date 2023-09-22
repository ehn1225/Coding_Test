//그래프 이론 - 4 커리큐럼
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int degree[501] = {0, };
	int time[501] = { 0, };
	int sum[501] = { 0, };
	vector<int> graph[501];
	queue<int> q;
	
	cin >> n;

	for (int i = 1; i < n + 1; i++) {
		int a;
		cin >> a;
		time[i] = a;
		sum[i] = a;
		cin >> a;
		while (a != -1) {
			graph[a].push_back(i); //선이수과목에 지금 과목을 알려줌
			degree[i]++;
			cin >> a;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (auto it : graph[num]) {
			sum[it] = max(sum[it], sum[num] + time[it]);
			degree[it]--;
			if (degree[it] == 0)
				q.push(it);
		}
	}
	for (int i = 1; i < n + 1; i++) {
		cout << sum[i] << endl;
	}

}
