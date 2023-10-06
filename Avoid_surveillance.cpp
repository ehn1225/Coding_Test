//DFS/BFS 문제- 20 감시 피하기
#include <bits/stdc++.h>
using namespace std;
int n;
char maps[6][6] = { 0, };
vector<pair<int, int>> teacher;
bool result = false;

bool check() {
	for (auto it : teacher) {
		int x = it.first;
		int y = it.second;
		//선생을 기준으로 상하좌우에 학생이 있는지 확인
		for (int i = x-1; i > -1; i--) {	//상
			if (maps[i][y] == 'O')
				break;
			if (maps[i][y] == 'S')
				return false;
		}
		for (int i = x + 1; i < n; i++) {	//하
			if (maps[i][y] == 'O')
				break;
			if (maps[i][y] == 'S')
				return false;
		}
		for (int i = y-1; i > -1; i--) {	//좌
			if (maps[x][i] == 'O')
				break;
			if (maps[x][i] == 'S')
				return false;
		}
		for (int i = y + 1; i < n; i++) {	//우
			if (maps[i][y] == 'O')
				break;
			if (maps[i][y] == 'S')
				return false;
		}
	}
	
	return true;
}

void dfs(int depth) {
	if (depth == 3) {
		if (check()) {
			result = true;
		}
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
			char c;
			cin >> c;
			maps[i][j] = c;
			if (c == 'T')
				teacher.push_back({ i, j });
		}
	}
	dfs(0);
	if (result) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}