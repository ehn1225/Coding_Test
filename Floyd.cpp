//최단 경로 문제 - 37 플로이드
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
	int n, m;
	cin >> n >> m;
	
	int cost[101][101];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp = cost[i][j];
			cout << ((tmp == INF) ? 0 : tmp) << " ";
		}
		cout << '\n';
	}

}