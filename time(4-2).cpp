#include <bits/stdc++.h>
using namespace std;

int h, cnt;

// Ư���� �ð� �ȿ� '3'�� ���ԵǾ� �ִ����� ����
bool check(int h, int m, int s) {
	if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
		return true;
	return false;
}

int main() {

	// H�� �Է¹ޱ� 
	cin >> h;
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				// �� �ð� �ȿ� '3'�� ���ԵǾ� �ִٸ� ī��Ʈ ����
				if (check(i, j, k)) cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;

}

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int second = (n+1) * 3600;
	int result = 0;

	for (int i = 0; i < second; i++) {
		int hour = i / 3600;
		int minute = (i % 3600) / 60;
		int second = i % 60;

		if (hour % 10 == 3 || minute / 10 == 3 || minute % 10 == 3 || second / 10 == 3 || second % 10 == 3) {
			result++;
		}

	}

	cout << result << endl;

}
*/