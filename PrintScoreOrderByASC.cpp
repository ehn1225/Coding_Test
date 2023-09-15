//정렬 - 3 성적이 낮은 순서로 학생 출력하기
#include <bits/stdc++.h>
using namespace std;

class STUDENT {
public:
	int score;
	string name;
	STUDENT(int score, string name) {
		this->name = name;
		this->score = score;
	}
	bool operator < (STUDENT &b) {
		return score < b.score;
	}
};

int main() {
	int n;
	cin >> n;

	vector<STUDENT> v;

	for (int i = 0; i < n; i++) {
		int score;
		string name;
		cin >> name >> score;
		STUDENT tmp = STUDENT(score, name);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (auto it : v)
		cout << it.name << " ";

}