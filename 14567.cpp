//백준 14567 - 선수과목
#include <bits/stdc++.h>
using namespace std;
bool graph[1001][1001] = { 0, };

int main() {
	int n, m;
	cin >> n >> m;;
	vector<int> result(n + 1, 1);
	vector<int> indegree(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		indegree[b]++;
	}

	//result에 최대값을 갱신하는 방식
	queue<int> q;
	for (int i = 1; i < n + 1; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 1; i < n + 1; i++) {
			if (graph[node][i] == 1) {
				result[i] = max(result[i], result[node] + 1);
				indegree[i]--;
				if (indegree[i] == 0) {
					q.push(i);
				}
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		cout << result[i] << '\n';
	}

}