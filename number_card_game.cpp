//�׸��� - ���� ī�� ����
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	int result;

	// N, M�� ������ �������� �����Ͽ� �Է� �ޱ�
	cin >> n >> m;

	// �� �پ� �Է� �޾� Ȯ���ϱ�
	for (int i = 0; i < n; i++) {
		// ���� �ٿ��� '���� ���� ��' ã��
		int min_value = 10001;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			min_value = min(min_value, x);
		}
		// '���� ���� ��'�� �߿��� ���� ū �� ã��
		result = max(result, min_value);
	}

	cout << result << '\n'; // ���� ��� ���

}

/*
int n, m;
	vector <int> v;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int min = 10001;
		for(int j = 0; j < m; j++){
			int tmp;
			cin >> tmp;
			if (tmp < min)
				min = tmp;
		}
		v.push_back(min);
	}
	sort(v.begin(), v.end());

	cout << v.at(n - 1) << endl;
*/