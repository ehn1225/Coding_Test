//최단 경로 - 2 미래 도시
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int graph[101][101] = { 0, };
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
		graph[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int x, k;
	cin >> x >> k;

	//플로이드 워셜 알고리즘
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int answer = graph[1][k] + graph[k][x];
	if (answer < INF)
		cout << answer << '\n';
	else
		cout << -1 << '\n';

}