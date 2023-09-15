//정렬 - 4 두 배열의 원소 교체
#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, k;
	vector<int> a;
	vector<int> b;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);

	// 첫 번째 인덱스부터 확인하며, 두 배열의 원소를 최대 K번 비교 
	for (int i = 0; i < k; i++) {
		// A의 원소가 B의 원소보다 작은 경우
		if (a[i] < b[i]) swap(a[i], b[i]); // 두 원소를 교체
		// A의 원소가 B의 원소보다 크거나 같을 때, 반복문을 탈출
		else break;
	}

	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];

	cout << sum << endl;

}