//구현 - 2 왕실의 나이트
#include <bits/stdc++.h>
using namespace std;

//상 - 좌,우; 우 - 상,하; 하 - 좌,우, 좌 - 상,하
int dx[] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dy[] = {-1, 1, 2, 2, -1, 1, -2, -2};
vector<pair<int, int>> steps = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}};

int main() {
	string pos;
	getline(cin, pos);
	int x = pos[1] - '0';
	int y = pos[0] - 'a' + 1;

	int answer = 0;
	//dx, dy 배열을 이용한 형태
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || nx > 8 || ny < 1 || ny > 8)
			continue;

		answer++;
	}

	//steps 변수를 이용한 형태
	/*
	for (auto it : steps) {
		int nx = x + it.first;
		int ny = y + it.second;

		if (nx < 1 || nx > 8 || ny < 1 || ny > 8)
			continue;

		answer++;
	}
	*/

	cout << answer << '\n';

}