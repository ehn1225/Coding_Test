//정렬 - 2 위에서 아래로
#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
	return a > b;
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

	//compare 함수를 선언하여 오름차순 정렬 방법
	//sort(v.begin(), v.end(), compare);

	//내림차순으로 정렬 후 reverse 하는 방법
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	for (auto it : v)
		cout << it << ' ';

}