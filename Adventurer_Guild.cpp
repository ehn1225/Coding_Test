//그리디 문제 - 1 모험가 길드
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	int result = 0; // 총 그룹의 수
	int count = 0; // 현재 그룹에 포함된 모험가의 수

	for (int i = 0; i < n; i++) { // 공포도를 낮은 것부터 하나씩 확인하며
		count += 1; // 현재 그룹에 해당 모험가를 포함시키기
		if (count >= arr[i]) { // 현재 그룹에 포함된 모험가의 수가 현재의 공포도 이상이라면, 그룹 결성
			result += 1; // 총 그룹의 수 증가시키기
			count = 0; // 현재 그룹에 포함된 모험가의 수 초기화
		}
	}

	cout << result << endl;
}