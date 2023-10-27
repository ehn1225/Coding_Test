//최단 경로 문제 - 39 화성 탐사
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int dx[] = { -1, 0, 1, 0 };
int dy[] = {0, 1, 0, -1};

int main() {
	int t;
	cin >> t;
	
	for (int c = 0; c < t; c++) {
		int n;
		cin >> n;
		vector<vector<int>> maps(n, vector<int>(n, 0));
		vector<vector<int>> d(n, vector<int>(n, INF));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> maps[i][j];
			}
		}

		d[0][0] = maps[0][0];
		priority_queue < pair<int, pair<int, int>>> pq;
		pq.push({ -maps[0][0], {0, 0} });

		while (!pq.empty()) {
			int cost = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			if (d[x][y] < cost) continue;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;

				int nextCost = cost + maps[nx][ny];
				if (d[nx][ny] > nextCost) {
					d[nx][ny] = nextCost;
					pq.push({ -nextCost, {nx, ny} });
				}
			}
		}

		cout << d[n - 1][n - 1] << '\n';

	}

}