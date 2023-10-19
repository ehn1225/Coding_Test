//DFS/BFS - 3 음료수 얼려 먹기
#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(vector<vector<int>> graph, int x, int y, vector<vector<bool>>& visited) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (graph[nx][ny] == 0 && visited[nx][ny] == false) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin.ignore();

	vector<vector<int>> graph(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, 0));

	for (int i = 0; i < n; i++) {
		string tmp;
		getline(cin, tmp);
		for (int j = 0; j < m; j++) {
			graph[i][j] = tmp[j] - '0';
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0 && visited[i][j] == false) {
				bfs(graph, i, j, visited);
				answer++;
			}
		}
	}

	cout << answer << '\n';
}