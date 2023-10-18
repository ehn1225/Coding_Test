//구현 - 3 게임 개발
#include <bits/stdc++.h>
using namespace std;

//북동남서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int turnLeft(int n) {
	n--;
	if (n < 0)
		n = 3;
	return n;
}

int main() {
	int n, m;
	cin >> n >> m;

	int x, y, d;
	cin >> x >> y >> d;

	int maps[50][50];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maps[i][j];
		}
	}
	int turn_count = 0;
	int answer = 1;
	maps[x][y] = 1;
	while (1) {
		d = turnLeft(d);
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (maps[nx][ny] == 0) {
			x = nx;
			y = ny;
			maps[nx][ny] = 1;
			turn_count = 0;
			answer++;
		}
		else {
			turn_count++;
		}

		if (turn_count == 4) {
			turn_count = 0;
			int nx = x - dx[d];
			int ny = y - dy[d];
			if (maps[nx][ny] == 0) {
				x = nx;
				y = ny;
			}
			else {
				break;
			}

		}

	}

	cout << answer << '\n';

}