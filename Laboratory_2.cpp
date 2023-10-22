//DFS/BFS - 16 연구소
//백준 14502
#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int result = 0;
int n, m;

int SpreadVirus(vector<vector<int>> maps) {
	//바이러스를 확산시키고, 안전 영역의 크기를 반환함.
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maps[i][j] == 2)
				q.push({i, j});
		}
	}

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (maps[nx][ny] == 0) {
				maps[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maps[i][j] == 0)
				answer++;
		}
	}
	return answer;
}

void dfs(int depth, vector<vector<int>>& maps) {
	if (depth == 3) {
		vector<vector<int>> testMaps(maps);
		int case_result = SpreadVirus(testMaps);
		result = max(result, case_result);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maps[i][j] == 0) {
					maps[i][j] = 1;
					dfs(depth + 1, maps);
					maps[i][j] = 0;
				}
					
			}
		}
	}
}

int main() {

	cin >> n >> m;

	vector<vector<int>> maps(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
		}
	}

	dfs(0, maps);

	cout << result << '\n';

}