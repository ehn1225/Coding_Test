//다이나믹 프로그래밍 - 35 못생긴 수
#include <bits/stdc++.h>
using namespace std;

int n;
int ugly[1000]; // 못생긴 수를 담기 위한 테이블 (1차원 DP 테이블)

int main(void) {
	cin >> n;

	// 2배, 3배, 5배를 위한 인덱스
	int i2 = 0, i3 = 0, i5 = 0;
	// 처음에 곱셈 값을 초기화
	int next2 = 2, next3 = 3, next5 = 5;

	ugly[0] = 1; // 첫 번째 못생긴 수는 1
	// 1부터 n까지의 못생긴 수들을 찾기
	for (int l = 1; l < n; l++) {
		// 가능한 곱셈 결과 중에서 가장 작은 수를 선택
		ugly[l] = min(next2, min(next3, next5));
		// 인덱스에 따라서 곱셈 결과를 증가
		if (ugly[l] == next2) {
			i2 += 1;
			next2 = ugly[i2] * 2;
		}
		if (ugly[l] == next3) {
			i3 += 1;
			next3 = ugly[i3] * 3;
		}
		if (ugly[l] == next5) {
			i5 += 1;
			next5 = ugly[i5] * 5;
		}
	}

	// n번째 못생긴 수를 출력
	cout << ugly[n - 1] << '\n';
}
/*
//it works, but it is not Dynamic Programming
int main() {
	int n;
	cin >> n;
	
	vector<int> v = {1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15};
	int a = 16;
	while (v.size() < n) {
		int left = a;

		while (left > 1) {
			if (left % 5 == 0) {
				left /= 5;
				continue;
			}
			else if (left % 3 == 0) {
				left /= 3;
				continue;
			}
			else if (left % 2 == 0) {
				left /= 2;
				continue;
			}

			break;
		}

		if (left == 1)
			v.push_back(a);
		a++;
	}

	cout << v[n - 1] << endl;

}
*/