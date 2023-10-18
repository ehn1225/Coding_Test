//그리디 - 3 숫자 카드 게임
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	//(0, 0) 부터 n * m개의 카드를 입력하고, 해당 행의 최솟값을 구함.
	//또한 각 행의 최솟값을 비교하여 제일 큰 값을 저장함.
	//각 행마다 가장 작은 수를 찾은 뒤에 그 수 중에서 가장 큰 수를 찾는다.
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int row_min = 1e9;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			row_min = min(row_min, a);
		}
		answer = max(answer, row_min);
	}

	cout << answer << '\n';

}