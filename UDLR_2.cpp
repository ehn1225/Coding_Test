//구현 - 예제 4-1 상하좌우
#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char move_type[] = { 'U', 'R', 'D', 'L' };

int main() {
	int n;
	cin >> n;

	int x = 1, y = 1;

	string plan;
	cin.ignore();
	getline(cin, plan);

	for (int i = 0; i < plan.length(); i += 2) {
		char next = plan[i];
		int nx = x;
		int ny = y;
		for (int i = 0; i < 4; i++) {
			if (next == move_type[i]) {
				nx += dx[i];
				ny += dy[i];
				break;
			}
		}
		
		if (nx < 1 || nx > n || ny < 1 || ny > n)
			continue;
		x = nx;
		y = ny;
	}

	cout << x << ' ' << y << '\n';

}