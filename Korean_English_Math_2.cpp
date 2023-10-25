//정렬 문제 - 23 국영수
//백준 10825
#include <bits/stdc++.h>
using namespace std;

class STUDENT {
public:
	int korean;
	int english;
	int math;
	string name;
	STUDENT(string name, int korean, int english, int math) {
		this->name = name;
		this->korean = korean;
		this->english = english;
		this->math = math;
	}

	bool operator < (const STUDENT& other) {
		if (korean == other.korean && english == other.english && math == other.math) {
			return name < other.name;
		}
		if (korean == other.korean && english == other.english) {
			return math > other.math;
		}		
		if (korean == other.korean) {
			return english < other.english;
		}		
		return korean > other.korean;
	}
};

int main() {
	int n;
	cin >> n;

	vector<STUDENT> students;
	for (int i = 0; i < n; i++) {
		string name;
		int a, b, c;
		cin >> name >> a >> b >> c;
		students.push_back(STUDENT(name, a, b, c));
	}

	sort(students.begin(), students.end());

	for (STUDENT it : students) {
		cout << it.name << '\n';
	}

}