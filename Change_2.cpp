//그리디 - 예제 3-1 거스름돈
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int answer = 0;
	vector<int> coin = { 500, 100, 50, 10 };

	for (int it : coin) {
		answer += (n / it);
		n = n % it;
	}

	cout << answer << '\n';
}