//구현 문제 - 11 뱀
//백준 3190
//큐의 front가 뱀의 꼬리, 큐의 back가 뱀의 머리
#include <bits/stdc++.h>
using namespace std;
//상 우 하 좌
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char command[10001] = { 0, };

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> maps(n + 2, vector<int>(n + 2, 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			maps[i][j] = 0;
		}
	}

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		maps[a][b] = 2;
	}

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int a;
		char c;
		cin >> a >> c;
		command[a] = c;
	}
	int head = 1;
	queue<pair<int, int>> snake;
	snake.push({ 1, 1 });

	int answer = 0;
	while (!snake.empty()) {
		answer++;
		int nx = snake.back().first + dx[head];
		int ny = snake.back().second + dy[head];

		if (maps[nx][ny] == 1) {
			break;
		}
		if (maps[nx][ny] == 2) {
			maps[nx][ny] = 0;
		}
		else {
			maps[snake.front().first][snake.front().second] = 0;
			snake.pop();
		}
		snake.push({ nx, ny });
		maps[nx][ny] = 1;

		if (command[answer] != 0) {
			if (command[answer] == 'L') {
				head = (head - 1) % 4;
			}
			else {
				head = (head + 1) % 4;
			}

		}
	}

	cout << answer << '\n';


}