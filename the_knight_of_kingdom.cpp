//2 실전문제 - 왕실의 나이트
#include <bits/stdc++.h>
using namespace std;

string inputData;

// 나이트가 이동할 수 있는 8가지 방향 정의
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main() {
	// 현재 나이트의 위치 입력받기
	cin >> inputData;
	int row = inputData[1] - '0';
	int column = inputData[0] - 'a' + 1;

	// 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
	int result = 0;
	for (int i = 0; i < 8; i++) {
		// 이동하고자 하는 위치 확인
		int nextRow = row + dx[i];
		int nextColumn = column + dy[i];
		// 해당 위치로 이동이 가능하다면 카운트 증가
		if (nextRow >= 1 && nextRow <= 8 && nextColumn >= 1 && nextColumn <= 8) {
			result += 1;
		}
	}

	cout << result << '\n';
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int x = 0, y = 0;

bool check(int x, int y) {
	if (x < 0 || y < 0 || x > 7 || y >7)
		return false;

	return true;
}

int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[] = {2, 2, -1, 1, -2, -2, -1, 1};

int main() {
	int result = 0;
	string pos;

	cin >> pos;

	x = pos[1] - '1';
	y = pos[0] - 'a';

	for (int i = 0; i < 8; i++) {
		if (check(x + dx[i], y + dy[i]))
			result++;
	}

	cout << result << endl;

}
*/