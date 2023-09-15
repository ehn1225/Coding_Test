//���� - 4 �� �迭�� ���� ��ü
#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, k;
	vector<int> a;
	vector<int> b;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	// ù ��° �ε������� Ȯ���ϸ�, �� �迭�� ���Ҹ� �ִ� K�� �� 
	for (int i = 0; i < k; i++) {
		// A�� ���Ұ� B�� ���Һ��� ���� ���
		if (a[i] < b[i]) swap(a[i], b[i]); // �� ���Ҹ� ��ü
		// A�� ���Ұ� B�� ���Һ��� ũ�ų� ���� ��, �ݺ����� Ż��
		else break;
	}

	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];

	cout << sum << endl;

}