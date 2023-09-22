//그리디 문제 - 2 곱하기 혹은 더하기
#include <bits/stdc++.h>
using namespace std;

int main() {
	int result = 0;
	string tmp;
	getline(cin, tmp);

	for (int i = 0; i < tmp.length(); i++) {
		int n = tmp[i] - '0';
		if (n <= 1 || result <= 1)
			result += n;
		else
			result *= n;
	}

	cout << result;

}