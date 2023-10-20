//이진 탐색 - 2 부품 찾기
#include <bits/stdc++.h>
using namespace std;

//set 자료구조 방법
int main() {
	int n, m;
	cin >> n;

	set<int> s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	cin >> m;
	vector<int> request;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		request.push_back(a);
	}

	for (int i = 0; i < m; i++) {
		set<int>::iterator it = s.find(request[i]);
		if (it != s.end())
			cout << "yes ";
		else
			cout << "no ";
	}

	cout << '\n';

}

//계수 정렬 방법
/*
int arr[1000001] = { 0, };
int main() {
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a]++;
	}

	cin >> m;
	vector<int> request;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		request.push_back(a);
	}

	for (int i = 0; i < m; i++) {
		int answer = arr[request[i]];
		if (answer == 0)
			cout << "no ";
		else
			cout << "yes ";
	}

	cout << '\n';

}
*/

//이진탐색 방법
/*
int BinarySearch(vector<int> items, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (items[mid] == target)
			return mid;
		else if (items[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
}

int main() {
	int n, m;
	cin >> n;

	vector<int> items;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		items.push_back(a);
	}

	sort(items.begin(), items.end());

	cin >> m;
	vector<int> request;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		request.push_back(a);
	}

	for (int i = 0; i < m; i++) {
		int answer = BinarySearch(items, request[i], 0, items.size() - 1);
		if (answer == -1)
			cout << "no ";
		else
			cout << "yes ";
	}

	cout << '\n';

}
*/