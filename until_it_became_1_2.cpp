//그리디 - 4 1이 될 때까지
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int answer = 0;
	while (1) {
		int target = (n / k) * k;
		answer += (n - target);
		n = target;

		if (n < k)
			break;
		answer++;
		n /= k;
	}

	answer += (n - 1);

	/*
	//하나씩 빼는 것이 비효율 적일 수도 있음
	while (n > 1) {
		if (n % k == 0)
			n /= k;
		else
			n--;
		answer++;
	}
	*/

	cout << answer << '\n';

}