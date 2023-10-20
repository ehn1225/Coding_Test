//이진 탐색 - 3 떡볶이 떡 만들기
#include <bits/stdc++.h>
using namespace std;

long long Sliced_mount(vector<int> v, int target) {
	long long answer = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > target)
			answer += (v[i] - target);
	}
	return answer;
}

int BinarySearch(vector<int> v, int target, int start, int end) {
	int result = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		long long calc_result = Sliced_mount(v, mid);
		if (calc_result < target) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n >> m;

	int max_value = 0;
	vector<int> rice_cake;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		max_value = max(max_value, a);
		rice_cake.push_back(a);
	}

	//자르는 높이를 이진 탐색으로 찾아감
	int answer = BinarySearch(rice_cake, m, 0, max_value);
	cout << answer << '\n';

}