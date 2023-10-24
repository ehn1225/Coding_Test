//DFS/BFS - 21 인구 이동
//백준 16234
#include <bits/stdc++.h>
using namespace std;
int maps[50][50];
int unions[50][50];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, l, r;
int answer = 0;


void findUnite(int i, int j, int index) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> union_nation;
	int total = maps[i][j];

	union_nation.push_back({ i, j });
	q.push({ i, j });
	unions[i][j] = index;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (unions[nx][ny] != -1) continue;
			int diff = abs(maps[x][y] - maps[nx][ny]);
			if (l <= diff && diff <= r) {
				q.push({ nx, ny });
				union_nation.push_back({ nx, ny });
				total += maps[nx][ny];
				unions[nx][ny] = index;
			}
		}
	}

	int avg_population = total / union_nation.size();
	for (auto it : union_nation) {
		maps[it.first][it.second] = avg_population;
	}
}

int main() {
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
		}
	}

	while (true) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				unions[i][j] = -1;
			}
		}
		int index = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (unions[i][j] == -1) { // 해당 나라가 아직 처리되지 않았다면
					findUnite(i, j, index);
					index += 1;
				}
			}
		}
		// 모든 인구 이동이 끝난 경우
		if (index == n * n) break;
		answer += 1;
	}

	cout << answer << '\n';

}