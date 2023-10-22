//구현 문제 - 7 럭키 스트레이트
//백준 18406
#include <bits/stdc++.h>
using namespace std;

int main() {
	string score;
	cin >> score;

	int harf = score.length() / 2;

	int answer = 0;
	for (int i = 0; i < harf; i++) {
		answer += score[i] - '0';
	}
	for (int i = harf; i < score.length(); i++) {
		answer -= score[i] - '0';
	}

	if (answer == 0)
		cout << "LUCKY" << '\n';
	else
		cout << "READY" << '\n';

}