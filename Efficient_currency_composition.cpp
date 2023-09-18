//DP - 5 ȿ������ ȭ�� ����
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int main(void) {
    // ���� N, M�� �Է¹ޱ�
    cin >> n >> m;

    // N���� ȭ�� ���� ������ �Է� �ޱ�
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // �� �� ���� ����� �����ϱ� ���� DP ���̺� �ʱ�ȭ
    vector<int> d(m + 1, 10001);

    // ���̳��� ���α׷���(Dynamic Programming) ����(���Ҿ�)
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= m; j++) {
            // (i - k)���� ����� ����� �����ϴ� ���
            if (d[j - arr[i]] != 10001) {
                d[j] = min(d[j], d[j - arr[i]] + 1);
            }
        }
    }

    // ���� ��� ���
    if (d[m] == 10001) { // ���������� M���� ����� ����� ���� ���
        cout << -1 << '\n';
    }
    else {
        cout << d[m] << '\n';
    }
}

/*
bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, m;
	int arr[10001];
	vector<int> unit;
	cin >> n >> m;

	for (int i = 0; i < 10001; i++) {
		arr[i] = 10001;
	}
	arr[0] = 0;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp] = 1;
		unit.push_back(tmp);
	}
	sort(unit.begin(), unit.end(), compare);

	for (int i = unit[0]; i <= m; i++) {
		for (auto it : unit) {
			if (i - it > 0) {
				arr[i] = min(arr[i], arr[i - it] + 1);
				cout << arr[i] << ", " << arr[i - it] << endl;
				break;
			}
		}
	}

	cout << ((arr[m] == 10001) ? -1 : arr[m]) << endl;
}
*/