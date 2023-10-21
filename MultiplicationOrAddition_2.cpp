//그리디 문제 - 2 곱하기 혹은 더하기
//두 수에 대하여 연산을 수행할 때, 두 수 중에서 하나라도 1 이하인 경우에는 더하며, 두 수가 모두 2 이상인 경우에는 곱하면 된다
#include <bits/stdc++.h>
using namespace std;

int main() {
	string tmp;
	getline(cin, tmp);

	int result = 0;
	for (int i = 0; i < tmp.length(); i++) {
		int n = (tmp[i] - '0');
		if (n < 2 || result < 2)
			result += n;
		else
			result *= n;
	}

	cout << result << '\n';

}