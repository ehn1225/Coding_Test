//이진탐색 - 3 떡볶이 떡 만들기
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
	
	// 이진 탐색을 위한 시작점과 끝점 설정
	int start = 0;
	int end = 1e9;
	// 이진 탐색 수행 (반복적) 
	int result = 0;
	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			// 잘랐을 때의 떡의 양 계산
			if (v[i] > mid) total += v[i] - mid;
		}
		if (total < m) { // 떡의 양이 부족한 경우 더 많이 자르기(왼쪽 부분 탐색)
			end = mid - 1;
		}
		else { // 떡의 양이 충분한 경우 덜 자르기(오른쪽 부분 탐색)
			result = mid; // 최대한 덜 잘랐을 때가 정답이므로, 여기에서 result에 기록 
			start = mid + 1;
		}
	}

	cout << result << endl;
}

/*
//순차탐색이므로 시간초과 발생 가능

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