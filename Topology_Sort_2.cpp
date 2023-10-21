//그래프 이론 - 위상 정렬 Topology Sort
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v[100];
	vector<int> indegree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	//위상 정렬
	queue<int> q;
	for (int i = 1; i < n + 1; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << ' ';

		for (int i = 0; i < v[front].size(); i++) {
			int next = v[front][i];
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}

}