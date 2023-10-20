//최단 경로 - 플로이드 워셜(Floyd-Warshall)
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < n+1; i++) {
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (graph[i][j] == INF)
				cout << "INFINITY ";
			else
				cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
}