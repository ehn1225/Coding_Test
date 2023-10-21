//그리디 문제 - 3 문자열 뒤집기
#include <bits/stdc++.h>
using namespace std;

int main() {
	string tmp;
	cin >> tmp;

	//0으로 다 만들 것인지, 1로 다 만들 것인지 둘 중 최솟값

	bool check_1 = false;
	int count_1 = 0;	//모두 0으로 만드는 경우의 수
	bool check_0 = false;
	int count_0 = 0;	//모두 1로 만드는 경우의 수
	for (int i = 0; i < tmp.length(); i++) {
		//두 조건문을 합칠 수 있음.
		//모두 0으로 만드는 경우의 수
		if (tmp[i] == '0') {
			check_1 = false;
		}
		else {
			if (check_1 == false) {
				check_1 = true;
				count_1++;
			}
		}
		//모두 1로 만드는 경우의 수
		if (tmp[i] == '1') {
			check_0 = false;
		}
		else {
			if (check_0 == false) {
				check_0 = true;
				count_0++;
			}
		}
	}

	cout << min(count_0, count_1) << '\n';


}
