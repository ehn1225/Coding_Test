#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	int result = 0;

	// N, K를 공백을 기준으로 구분하여 입력 받기
	cin >> n >> k;

	while (true) {
		// N이 K로 나누어 떨어지는 수가 될 때까지만 1씩 빼기
		int target = (n / k) * k;
		result += (n - target);
		n = target;
		// N이 K보다 작을 때 (더 이상 나눌 수 없을 때) 반복문 탈출
		if (n < k) break;
		// K로 나누기
		result += 1;
		n /= k;
	}

	// 마지막으로 남은 수에 대하여 1씩 빼기
	result += (n - 1);
	cout << result << '\n';
}

/*
	int n, k;
	int answer = 0;

	cin >> n >> k;
	//하지만 N이 100억 이상의 큰 수가 되는 경우를 가정했을 때에도 빠르게 동작하려면, N이 K의 배수가 되도록 효율적으로 한 번에 빼는 방식으로 소스코드를 작성할 수 있다.
	//기존코드는 1씩 감소하므로 느리다.
	while (n > 2) {
		if (n % k != 0) {
			n--;
			answer++;
			continue;
		}
		while (n % k == 0) {
			n /= k;
			answer++;
		}
	}
	cout << answer << endl;
*/