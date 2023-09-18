//최단경로 - floyd warshall
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main() {
	// 노드의 개수(N), 간선의 개수(M)
	// 노드의 개수는 최대 500개라고 가정
	int distance[501][501];
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 501; i++) {
		fill(distance[i], distance[i] + 501, INF);
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i == j) distance[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		distance[a][b] = c;
	}

	for (int k = 1; k < n + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (distance[i][j] == INF) {
				cout << "INF" << " ";
			}
			else {
				cout << distance[i][j] << " ";
			}
		}
		cout << endl;
	}

}