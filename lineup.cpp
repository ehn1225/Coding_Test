//백준 2252 - 줄 세우기
#include <bits/stdc++.h>
using namespace std;

int indegree[32001] = { 0, };
vector<int> graph[32001];

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	vector<int> result;

	for (int i = 1; i < n + 1; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		result.push_back(num);
		for (auto it : graph[num]) {
			indegree[it]--;
			if (indegree[it] == 0)
				q.push(it);
		}
	}

	for (auto it : result) {
		cout << it << " ";
	}
	cout << endl;

}