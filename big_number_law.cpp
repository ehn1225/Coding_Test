//�׸��� - ū���� ��Ģ
#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v;
	int n, m, k, tmp;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end()); // �Է� ���� ���� �����ϱ�
	int first = v[n - 1]; // ���� ū ��
	int second = v[n - 2]; // �� ��°�� ū ��

	// ���� ū ���� �������� Ƚ�� ���
	int cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1);

	int result = 0;
	result += cnt * first; // ���� ū �� ���ϱ�
	result += (m - cnt) * second; // �� ��°�� ū �� ���ϱ�

	cout << result << endl;

	return 0;
}

/*
	vector<int> input;
	vector<int> answer;
	int n, m, k, tmp;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end()); //�������� ����
	int length = input.size();
	for (int i = 0; i < m; i++) {
		int option = 1;
		int a = input[length - 1];
		for (int j = 0; j < k; j++) {
			answer.push_back(a);
		}
		answer.push_back(input[length - 2]);
	}

	int sum = 0;
	for (int i = 0; i < m; i++) {
		sum += answer.at(i);
	}

	cout << sum << endl;
*/