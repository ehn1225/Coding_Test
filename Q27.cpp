//이진 탐색 - 27 정렬된 배열에서 특정 수의 개수 구하기
#include <bits/stdc++.h>
using namespace std;

// 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
int countByRange(vector<int>& v, int leftValue, int rightValue) {
	vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
	vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
	return rightIndex - leftIndex;
}

int n, x;
vector<int> v;

int main() {
	// 데이터의 개수 N, 찾고자 하는 값 x 입력받기
	cin >> n >> x;

	// 전체 데이터 입력 받기
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	// 값이 [x, x] 범위에 있는 데이터의 개수 계산
	int cnt = countByRange(v, x, x);

	// 값이 x인 원소가 존재하지 않는다면
	if (cnt == 0) {
		cout << -1 << '\n';
	}
	//  값이 x인 원소가 존재한다면
	else {
		cout << cnt << '\n';
	}
}
/*
int BinarySearch(vector<int> v, int key, int left, int right) {
	int middle = (left + right) / 2;

	while (left < right){
		if (v[middle] == key)
			return middle;
		else if (v[middle] < key) {
			return BinarySearch(v, key, middle + 1, right);
		}
		else {
			return BinarySearch(v, key, left, middle + 1);
		}
	}

	return -1;
}

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int pos = BinarySearch(v, x, 0, n);

	if (pos != -1) {
		int answer = 0;
		for (int i = pos; i >= 0; i--) {
			if (v[i] == x) {
				answer++;
			}
		}
		for (int i = pos + 1; i < n; i++) {
			if (v[i] == x) {
				answer++;
			}
		}
		cout << answer << endl;
	}
	else {
		cout << "-1" << endl;
	}
}
*/