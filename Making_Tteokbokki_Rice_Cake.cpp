//����Ž�� - 3 ������ �� �����
#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, m;
	vector<int> v;

	cin >> n >> m;
	int max = 0;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	// ���� Ž���� ���� �������� ���� ����
	int start = 0;
	int end = 1e9;
	// ���� Ž�� ���� (�ݺ���) 
	int result = 0;
	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			// �߶��� ���� ���� �� ���
			if (v[i] > mid) total += v[i] - mid;
		}
		if (total < m) { // ���� ���� ������ ��� �� ���� �ڸ���(���� �κ� Ž��)
			end = mid - 1;
		}
		else { // ���� ���� ����� ��� �� �ڸ���(������ �κ� Ž��)
			result = mid; // �ִ��� �� �߶��� ���� �����̹Ƿ�, ���⿡�� result�� ��� 
			start = mid + 1;
		}
	}

	cout << result << endl;
}

/*
//����Ž���̹Ƿ� �ð��ʰ� �߻� ����

	sort(v.begin(), v.end(), compare);

	int h = v[0];
	int sum = 0;
	while (sum < m) {
		for(int i = 0; i < n; i++) {
			int left = v[i] - h;
			if (left < 0)
				break;
			else
				sum += left;
		}
		h--;
	}
*/