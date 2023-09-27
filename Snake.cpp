//구현 문제 - 11 뱀
#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1}; //동 남 서 북
int dy[] = {1, 0, -1, 0};

int main() {
	int maps[101][101] = {0, };
	char command[10001] = { 0, };

	int n, k, l;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		maps[a][b] = 2;
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int a;
		char b;
		cin >> a >> b;
		command[a] = b;
	}

	deque<pair<int, int>> snake;
	snake.push_front({ 1, 1 });
	maps[1][1] = 1;
	int toward = 0;

	int result = 0;
	while (!snake.empty()) {
		result++;
		int headX = snake.front().first;
		int headY = snake.front().second;

		int newHeadX = headX + dx[toward];
		int newHeadY = headY + dy[toward];

		if (newHeadX <= 0 || newHeadX > n || newHeadY <= 0 || newHeadY > n || maps[newHeadX][newHeadY] == 1) {
			//벽과 충돌하거나 자신의 몸과 충돌할 경우
			break;
		}

		snake.push_front({ newHeadX, newHeadY });
		if (maps[newHeadX][newHeadY] != 2) {
			//사과가 없다면 꼬리 자르기
			int backX = snake.back().first;
			int backY = snake.back().second;
			maps[backX][backY] = 0;
			snake.pop_back();
		}
		maps[newHeadX][newHeadY] = 1;

		if (command[result] != 0) {
			if (command[result] == 'L') {
				toward = (toward - 1) % 4;
			}
			if (command[result] == 'D') {
				toward = (toward + 1) % 4;
			}
		}

	}

	cout << result << endl;


}