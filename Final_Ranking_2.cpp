//그래프 이론 문제 - 45 최종 순위
//백준 3665
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, 0));
		vector<int> lastRanking;
		vector<int> indegree(n + 1, 0);

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			lastRanking.push_back(a);
		}
		//내가 이긴 노드들에게 1 표시
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				graph[lastRanking[i]][lastRanking[j]] = 1;
				indegree[lastRanking[j]]++;
			}
		}

		int m;
		cin >> m;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (graph[a][b] == 1) {
				graph[a][b] = 0;
				graph[b][a] = 1;
				indegree[a]++;
				indegree[b]--;
			}
			else {
				graph[a][b] = 1;
				graph[b][a] = 0;
				indegree[a]--;
				indegree[b]++;
			}
		}

		queue<int> q;
		for (int i = 1; i < n + 1; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		bool cycle = false;
		bool multi = false;
		vector<int> ranking;
		for (int i = 0; i < n; i++) {
			if (q.size() == 0) {
				cycle = true;
				break;
			}
			if (q.size() >= 2) {
				multi = true;
				break;
			}

			int node = q.front();
			ranking.push_back(node);
			q.pop();

			for (int j = 1; j < n + 1; j++) {
				if (graph[node][j] == 1) {
					indegree[j]--;
					if (indegree[j] == 0) {
						q.push(j);
					}
				}

			}
		}

		if (ranking.size() != n) cycle = true;

		if (cycle) {
			cout << "IMPOSSIBLE" << '\n';
		}
		else if (multi) {
			cout << "?" << '\n';
		}
		else {
			for (int it : ranking) {
				cout << it << ' ';
			}
			cout << '\n';
		}
	}
}