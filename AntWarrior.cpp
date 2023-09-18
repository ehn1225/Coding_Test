//DP - 3 개미전사
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int arr[101] = { 0, };
	int sum[101] = { 0, };
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		arr[i] = tmp;
	}

	// 다이나믹 프로그래밍(Dynamic Programming) 진행(보텀업)
	sum[0] = arr[0];
	sum[1] = max(arr[0], arr[1]);
	for (int i = 2; i < n; i++) {
		sum[i] = max(sum[i - 1], sum[i - 2] + arr[i]);
	}

	cout << sum[n - 1] << endl;

}

/*
	int n;
	int arr[101] = { 0, };
	int sum[101] = { 0, };
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		arr[i] = tmp;
	}
	sum[0] = arr[0];
	sum[1] = arr[1];
	sum[2] = arr[0] + arr[2];

	for (int i = 3; i < n; i++) {
		sum[i] = sum[i - 2] + arr[i];
		if(sum[i - 3] + arr[i] > sum[i])
			sum[i] = sum[i - 3] + arr[i];
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (sum[i] >= max)
			max = sum[i];
	}

	cout << max << endl;
*/