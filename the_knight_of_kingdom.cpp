//2 �������� - �ս��� ����Ʈ
#include <bits/stdc++.h>
using namespace std;

string inputData;

// ����Ʈ�� �̵��� �� �ִ� 8���� ���� ����
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main() {
	// ���� ����Ʈ�� ��ġ �Է¹ޱ�
	cin >> inputData;
	int row = inputData[1] - '0';
	int column = inputData[0] - 'a' + 1;

	// 8���� ���⿡ ���Ͽ� �� ��ġ�� �̵��� �������� Ȯ��
	int result = 0;
	for (int i = 0; i < 8; i++) {
		// �̵��ϰ��� �ϴ� ��ġ Ȯ��
		int nextRow = row + dx[i];
		int nextColumn = column + dy[i];
		// �ش� ��ġ�� �̵��� �����ϴٸ� ī��Ʈ ����
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