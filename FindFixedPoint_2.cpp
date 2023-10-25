//이진 탐색 - 28 고정점 찾기
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> v, int start, int end) {
	if (start > end) return -1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (mid == v[mid]) {
			return mid;
		}
		else if (v[mid] > mid)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int answer = BinarySearch(v, 0, n - 1);
	cout << answer << '\n';

}