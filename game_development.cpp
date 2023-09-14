#include <bits/stdc++.h>
using namespace std;

//북, 동, 남, 서
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void turn(int& d) {
	if (d == 0)
		d = 3;
	else
		d--;
}

int main() {
	int n, m;
	int x, y, d;
	int map[50][50] = { 0, };

	cin >> n >> m;
	cin >> x >> y >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	int result = 0;

	while (true){
		//4면이 막혔을 경우
		if (map[x - 1][y] == 1 && map[x + 1][y] == 1 && map[x][y - 1] == 1 && map[x][y + 1] == 1) {
			int nx = x - dx[d];
			int ny = y - dy[d];
			if (map[nx][ny] == 1) {
				break;
			}
			x = nx;
			y = ny;
		}

		turn(d);
		int nx = x + dx[d];
		int ny = y + dy[d];
		//cout << "(" << x << ", " << y << ", " << d << ")" << endl;
		if (map[nx][ny] == 0) {
			//cout << "(" << x << ", " << y << ") -> (" << nx << ", " << ny << ")" << endl;
			map[x][y] = 1;
			x = nx;
			y = ny;
			result++;
		}
	}
	cout << result + 1 << endl; // +1 : 초기 스폰 장소 카운트
}