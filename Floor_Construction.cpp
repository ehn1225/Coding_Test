//DP - 4 바닥 공사
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[1001] = { 0, };

	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 796796;
	}

	cout << arr[n] << endl;

}