//정렬 - 2 위에서 아래로
#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), compare);

	for (auto it : v) {
		cout << it << " ";
	}
}

/*
int main() {
	int n;
	int arr[100001] = {0, };
	cin >> n;

	memset(arr, 0, sizeof(int) * 100001);

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 100000; i > -1; i--) {
		for (int j = 0; j < arr[i]; j++)
			cout << i << " ";
	}
}
*/