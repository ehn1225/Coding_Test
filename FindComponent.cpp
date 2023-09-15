//이진탐색 - 2 부품 찾기
#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> v, int start, int end, int key) {
	if (start > end) return -1;

	int middle = (start + end) / 2;
	if (v[middle] == key)
		return middle;
	else if (v[middle] < key)
		return BinarySearch(v, middle + 1, end, key);
	else if (v[middle] > key)
		return BinarySearch(v, start, middle - 1 , key);
	else
		return -1;
}

int main() {
	int n, m;
	vector<int> items;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		items.push_back(tmp);
	}

	sort(items.begin(), items.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;

		if (BinarySearch(items, 0, n, tmp) != -1) {
			cout << "yes ";
		}
		else
			cout << "no ";
	}
}