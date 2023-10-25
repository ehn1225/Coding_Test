//이진 탐색 - 27 정렬된 배열에서 특정 수의 개수 구하기
#include <bits/stdc++.h>
using namespace std;

int BinarySearch_First(vector<int> v, int key, int start, int end) {
	if (start > end) return -1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (v[mid] == key && (v[mid-1] < key || mid == 0))
			return mid;
		else if (v[mid] >= key)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return -1;
}
int BinarySearch_Last(vector<int> v, int key, int start, int end) {
	if (start > end) return -1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (v[mid] == key && (v[mid + 1] > key || mid == v.size() - 1))
			return mid;
		else if (v[mid] <= key)
			start = mid + 1;
		else
			end = mid - 1;
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

	int left = BinarySearch_First(v, x, 0, n - 1);
	int right = BinarySearch_Last(v, x, 0, n - 1);
	if (left == -1 || right == -1)
		cout << -1 << '\n';
	else
		cout << (right - left) + 1 << '\n';
}


//lower_bound(), upper_bound() 함수를 이용하는 방법
/*
int main() {
	int n, x;
	cin >> n >> x;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	vector<int>::iterator left = lower_bound(v.begin(), v.end(), x);
	vector<int>::iterator right = upper_bound(v.begin(), v.end(), x);
	if (left == v.end() || right == v.end())
		cout << -1 << '\n';
	else
		cout << (right - left) << '\n';
}
*/