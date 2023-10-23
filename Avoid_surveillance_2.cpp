//DFS/BFS - 20 감시 피하기
//백준 18428
#include <bits/stdc++.h>
using namespace std;

char maps[6][6] = {0, };
vector<pair<int, int>> teacher;
int n;
bool result = false;

void dfs(int depth) {
	if (depth == 3) {
		if (result == true) {
			return;
		}

		//선생님의 사방으로 체크
		//벽에 막히면 중단, 학생을 만나면 검사 종료
		int clear = true;
		for (auto pos : teacher) {
			if (clear == false) break;
			int x = pos.first;
			int y = pos.second;
			int nx = x + 1;
			while (nx < n) {
				if (maps[nx][y] == 'O')
					break;
				if (maps[nx][y] == 'S') {
					clear = false;
				}
				nx++;
			}

			nx = x - 1;
			while (nx > -1) {
				if (maps[nx][y] == 'O')
					break;
				if (maps[nx][y] == 'S') {
					clear = false;
				}
				nx--;
			}
			int ny = y + 1;
			while (ny < n) {
				if (maps[x][ny] == 'O')
					break;
				if (maps[x][ny] == 'S') {
					clear = false;
				}
				ny++;
			}

			ny = y - 1;
			while (ny > -1) {
				if (maps[x][ny] == 'O')
					break;
				if (maps[x][ny] == 'S') {
					clear = false;
				}
				ny--;
			}
		}

		result = clear;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maps[i][j] == 'X') {
					maps[i][j] = 'O';
					dfs(depth + 1);
					maps[i][j] = 'X';
				}
			}
		}

	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 'T') {
				teacher.push_back({ i, j });
			}
		}
	}

	dfs(0);

	if (result) {
		cout << "YES" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}
}