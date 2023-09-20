//그래프 - 2 미래도시
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
	int distance[101][101];

	for (int i = 0; i < 101; i++) {
		fill(distance[i], distance[i] + 101, INF);
	}

	int n, m;
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i == j) distance[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		distance[a][b] = 1;
		distance[b][a] = 1;
	}

	int x, k2;
	cin >> x >> k2;

	//플로이드 워셜
	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}

	int result = distance[1][k2] + distance[k2][x];
	if (result >= INF)
		cout << -1 << endl;
	else
		cout << result << endl;
}