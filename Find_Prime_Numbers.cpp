//기타 알고리즘 - 예제 B-1 소수 구하기
//백준 1929 - 소수 구하기
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	//에라토스테네스의 체 알고리즘
	vector<bool> v(m+1, 1);
	v[1] = 0; //1은 소수가 아니기에 제외

	for (int i = 2; i < (int)sqrt(m) + 1; i++) {
		if (v[i] == 1) {
			int j = 2;
			while (i * j <= m) {
				v[i * j] = 0;
				j++;
			}
		}
	}

	for (int i = n; i <= m; i++) {
		if (v[i] == 1) {
			printf("%d\n", i);
		}
	}
}