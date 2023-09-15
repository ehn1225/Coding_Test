//DP - 2 1로 만들기
#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[30001];
	for (int i = 0; i < 30001; i++)
		arr[i] = 0;

	int x;
	cin >> x;

	for (int i = 2; i < x+1; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			arr[i] = min(arr[i], arr[i / 2] + 1);
		}
		else if (i % 3 == 0) {
			arr[i] = min(arr[i], arr[i / 3] + 1);
		}
		else if (i % 5 == 0) {
			arr[i] = min(arr[i], arr[i / 5] + 1);
		}
	}

	cout << arr[x] << endl;

}