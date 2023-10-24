//구현 문제 - 13 치킨 배달
//백준 15686
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> chickens;
	vector<pair<int, int>> houses;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1)
				houses.push_back({ i + 1, j + 1 });
			else if(a == 2)
				chickens.push_back({ i + 1, j + 1 });
		}
	}

	vector<bool> binary(chickens.size(), 0);
	fill(binary.end() - m, binary.end(), 1);

	int answer = 1e9;
	do {
		vector<pair<int, int>> selectedChicken;
		for (int i = 0; i < chickens.size(); i++) {
			if (binary[i] == 1)
				selectedChicken.push_back({ chickens[i].first, chickens[i].second});
		}
		int chicken_distance_of_city = 0;
		for (int i = 0; i < houses.size(); i++) {
			int hx = houses[i].first;
			int hy = houses[i].second;

			int chicken_distance = 1e9;
			for (int j = 0; j < selectedChicken.size(); j++) {
				chicken_distance = min(chicken_distance, abs(selectedChicken[j].first - hx) + abs(selectedChicken[j].second - hy));
			}
			chicken_distance_of_city += chicken_distance;
		}

		answer = min(answer, chicken_distance_of_city);
	
	} while (next_permutation(binary.begin(), binary.end()));

	cout << answer << '\n';

}