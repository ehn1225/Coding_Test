//최단 경로 문제 - 37 플로이드
//백준 11404
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int graph[101][101];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
		graph[i][i] = 0;
	}


	for (int i = 0; i < m; i++) {
		int src, dst, cost;
		cin >> src >> dst >> cost;
		graph[src][dst] = min(graph[src][dst], cost);
	}

	//Floyd-Warshall
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' ';
		}
		cout << '\n';
	}

}