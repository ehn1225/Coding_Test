//최단 경로 문제 - 38 정확한 순위
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int graph[501][501];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n + 1; i++) {
		fill(graph[i], graph[i] + 501, INF);
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}

	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int answer = 0;

	for (int i = 1; i < n + 1; i++) {
		bool check = true;
		for (int j = 1; j < n + 1; j++) {
			if (i == j) continue;
			if (graph[i][j] == INF && graph[j][i] == INF) {
				check = false;
			}
		}
		if (check) {
			answer++;
		}
	}

	cout << answer << '\n';
}