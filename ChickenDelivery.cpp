//구현 문제 - 13 치킨 배달
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> chickenStore;
vector<pair<int, int>> house;

int distanceArr[13][101] = { 0, };

// 치킨 거리의 합을 계산하는 함수
int getSum(vector<pair<int, int> > candidates) {
	int result = 0;
	// 모든 집에 대하여
	for (int i = 0; i < house.size(); i++) {
		int hx = house[i].first;
		int hy = house[i].second;
		// 가장 가까운 치킨 집을 찾기
		int temp = 1e9;
		for (int j = 0; j < candidates.size(); j++) {
			int cx = candidates[j].first;
			int cy = candidates[j].second;
			temp = min(temp, abs(hx - cx) + abs(hy - cy));
		}
		// 가장 가까운 치킨 집까지의 거리를 더하기
		result += temp;
	}
	// 치킨 거리의 합 반환
	return result;
}

int main() {
	
	cin >> n >> m;
	
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1)
				house.push_back(make_pair(i, j));
			else if (tmp == 2)
				chickenStore.push_back(make_pair(i, j));
		}
	}

	// 모든 치킨 집 중에서 m개의 치킨 집을 뽑는 조합 계산
	vector<bool> binary(chickenStore.size());
	fill(binary.end() - m, binary.end(), true);

	// 치킨 거리의 합의 최소를 찾아 출력
	int result = 1e9;

	do {
		//now 백터에 후보군 치킨집 정보 입력
		vector<pair<int, int> > now;
		for (int i = 0; i < chickenStore.size(); i++) {
			if (binary[i]) {
				int cx = chickenStore[i].first;
				int cy = chickenStore[i].second;
				now.push_back({ cx, cy });
			}
		}
		result = min(result, getSum(now));
	} while (next_permutation(binary.begin(), binary.end()));

	cout << result << endl;
}