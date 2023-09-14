//그리디 - 숫자 카드 게임
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	int result;

	// N, M을 공백을 기준으로 구분하여 입력 받기
	cin >> n >> m;

	// 한 줄씩 입력 받아 확인하기
	for (int i = 0; i < n; i++) {
		// 현재 줄에서 '가장 작은 수' 찾기
		int min_value = 10001;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			min_value = min(min_value, x);
		}
		// '가장 작은 수'들 중에서 가장 큰 수 찾기
		result = max(result, min_value);
	}

	cout << result << '\n'; // 최종 답안 출력

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