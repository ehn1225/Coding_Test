//정렬 - 3 성적이 낮은 순서로 학생 출력하기
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;

	vector<pair<string, int>> v;
	
	for (int i = 0; i < n; i++) {
		int score;
		string name;
		cin >> name >> score;
		v.push_back({ name, score });
	}

	sort(v.begin(), v.end(), compare);

	for (auto it : v)
		cout << it.first << " ";

}