//구현 - 예제 4-2 시각
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int answer = 0;
	for (int hour = 0; hour <= n; hour++) {
		int h_10 = hour / 10;
		int h_1 = hour % 10;
		for (int minute = 0; minute < 60; minute++) {
			int m_10 = minute / 10;
			int m_1 = minute % 10;
			for (int second = 0; second < 60; second++) {		
				int s_10 = second / 10;
				int s_1 = second % 10;

				if (h_10 == 3 || h_1 == 3 || m_10 == 3 || m_1 == 3 || s_10 == 3 || s_1 == 3)
					answer++;
			}
		}
	}

	cout << answer << '\n';

}
