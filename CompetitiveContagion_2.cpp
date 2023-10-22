//DFS/BFS - 17 경쟁적 전염
#include <bits/stdc++.h>
using namespace std;

int maps[200][200];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

class VIRUS {
public:
	int index;
	int time;
	int x;
	int y;
	VIRUS(int a, int b, int c, int d) {
		index = a;
		time = b;
		x = c;
		y = d;
	}

	bool operator < (VIRUS& other) {
		return index < other.index;
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<VIRUS> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
			if (maps[i][j] != 0) {
				v.push_back(VIRUS(maps[i][j], 0, i, j));
			}
		}
	}

	sort(v.begin(), v.end());
	int s, x, y;
	cin >> s >> x >> y;

	queue<VIRUS> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
	}

	while (!q.empty()) {
		auto [virus, time, x, y] = q.front();
		q.pop();

		if (time == s) break;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (maps[nx][ny] == 0) {
				maps[nx][ny] = virus;
				q.push(VIRUS(virus, time + 1, nx, ny));
			}
		}
	}

	cout << maps[x - 1][y - 1] << '\n';
}

//시간 초과
/*
int n, k;
int maps[200][200];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1};

void bfs(int virus) {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maps[i][j] == virus) {
				q.push({ i, j });
				break;
			}
		}
	}

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (maps[nx][ny] == 0) {
				maps[nx][ny] = virus;
			}
		}
	}

}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
		}
	}

	int s, x, y;
	cin >> s >> x >> y;

	for (int time = 0; time < s; time++) {
		for (int virus = 1; virus < k + 1; virus++) {
			bfs(virus);
		}
	}

	cout << maps[x-1][y-1] << '\n';
}

*/