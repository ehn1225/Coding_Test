//DFS/BFS - 4 미로 탈출
#include <bits/stdc++.h>
using namespace std;
//visited 배열을 쓰느냐, 아니면 maps에 1씩 더하느냐 차이

//상우하좌
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	int n, m;
	cin >> n >> m;
	cin.ignore();
	
	//미로 초기화
	vector<vector<int>> maps(n + 1, vector<int>(m + 1));

	for (int i = 1; i < n+1; i++) {
		string tmp;
		getline(cin, tmp);
		for (int j = 1; j < m+1; j++) {
			maps[i][j] = tmp[j-1] - '0';
		}
	}

	//x좌표, y좌표
	queue<pair<int, int>> q;
	q.push({ 1, 1 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if (maps[nx][ny] == 0)
				continue;

			if (maps[nx][ny] == 1) {
				q.push({nx, ny});
				maps[nx][ny] = maps[x][y] + 1;
			}
		}
	}

 	cout << maps[n][m] << '\n';
}

/*
int main() {
	int n, m;
	cin >> n >> m;
	cin.ignore();

	//미로 초기화
	vector<vector<bool>> maps(n + 1, vector<bool>(m + 1));
	vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, 0));

	for (int i = 1; i < n+1; i++) {
		string tmp;
		getline(cin, tmp);
		for (int j = 1; j < m+1; j++) {
			maps[i][j] = tmp[j] - '0';
		}
	}

	//x좌표, y좌표, dlehd ghlttn
	queue<pair<pair<int, int>, int>> q;
	q.push({{ 1, 1 }, 1});
	visited[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int w = q.front().second;
		q.pop();

		if (x == n && y == m) {
			cout << w << '\n';
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;

			if (maps[nx][ny] == 1 && visited[nx][ny] == false) {
				q.push({ {nx, ny}, w + 1 });
				visited[nx][ny] = true;
			}
		}
	}
}
*/