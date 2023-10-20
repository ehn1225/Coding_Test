//이진탐색
#include <bits/stdc++.h>
using namespace std;

int BinarySearch_Recursive(vector<int> v, int target, int start, int end) {
	if (start > end) return -1;
	
	int mid = (start + end) / 2;
	if (v[mid] == target)
		return mid;
	else if (v[mid] < target)
		return BinarySearch_Recursive(v, target, mid + 1, end);
	else
		return BinarySearch_Recursive(v, target, start, mid - 1);

}

int BinarySearch_Loop(vector<int> v, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (v[mid] == target)
			return mid;
		else if (v[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return -1;
}

int main() {
	int n, target;
	cin >> n >> target;

	vector<int> list;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		list.push_back(a);
	}

	cout << BinarySearch_Recursive(list, target, 0, n - 1) << '\n';
	cout << BinarySearch_Loop(list, target, 0, n - 1) << '\n';

}