#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	int result = 0;

	// N, K�� ������ �������� �����Ͽ� �Է� �ޱ�
	cin >> n >> k;

	while (true) {
		// N�� K�� ������ �������� ���� �� �������� 1�� ����
		int target = (n / k) * k;
		result += (n - target);
		n = target;
		// N�� K���� ���� �� (�� �̻� ���� �� ���� ��) �ݺ��� Ż��
		if (n < k) break;
		// K�� ������
		result += 1;
		n /= k;
	}

	// ���������� ���� ���� ���Ͽ� 1�� ����
	result += (n - 1);
	cout << result << '\n';
}

/*
	int n, k;
	int answer = 0;

	cin >> n >> k;
	//������ N�� 100�� �̻��� ū ���� �Ǵ� ��츦 �������� ������ ������ �����Ϸ���, N�� K�� ����� �ǵ��� ȿ�������� �� ���� ���� ������� �ҽ��ڵ带 �ۼ��� �� �ִ�.
	//�����ڵ�� 1�� �����ϹǷ� ������.
	while (n > 2) {
		if (n % k != 0) {
			n--;
			answer++;
			continue;
		}
		while (n % k == 0) {
			n /= k;
			answer++;
		}
	}
	cout << answer << endl;
*/