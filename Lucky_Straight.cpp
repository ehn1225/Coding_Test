//구현문제 - 7 럭키 스트레이트
#include <bits/stdc++.h>
using namespace std;

string str;
int summary = 0;

int main(void) {
    cin >> str;

    // 왼쪽 부분의 자릿수의 합 더하기
    for (int i = 0; i < str.size() / 2; i++) {
        summary += str[i] - '0';
    }

    // 오른쪽 부분의 자릿수의 합 빼기
    for (int i = str.size() / 2; i < str.size(); i++) {
        summary -= str[i] - '0';
    }

    // 왼쪽 부분과 오른쪽 부분의 자릿수 합이 동일한지 검사
    if (summary == 0) cout << "LUCKY" << '\n';
    else cout << "READY" << '\n';
}

/*
int main() {
	int n;
	cin >> n;

	string num = to_string(n);
	int length = num.size();
	string a = num.substr(0, length / 2);
	string b = num.substr(length / 2, length);

	int sum_a = 0, sum_b = 0;
	for (int i = 0; i < length / 2; i++) {
		sum_a += ((char)(a[i]) - '0');
		sum_b += ((char)(b[i]) - '0');
	}

	if (sum_a == sum_b)
		cout << "LUCKY" << endl;
	else
		cout << "READY" << endl;

}*/