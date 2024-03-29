//정렬문제 - 23 국영수
#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int kor;
    int eng;
    int m;
    Student(string name, int kor, int eng, int m) {
        this->name = name;
        this->kor = kor;
        this->eng = eng;
        this->m = m;
    }
    /*
    [ 정렬 기준 ]
    1) 두 번째 원소를 기준으로 내림차순 정렬
    2) 두 번째 원소가 같은 경우, 세 번째 원소를 기준으로 오름차순 정렬
    3) 세 번째 원소가 같은 경우, 네 번째 원소를 기준으로 내림차순 정렬
    4) 네 번째 원소가 같은 경우, 첫 번째 원소를 기준으로 오름차순 정렬
    */
    bool operator <(Student& other) {
        if (this->kor == other.kor && this->eng == other.eng && this->m == other.m) {
            return this->name < other.name;
        }
        if (this->kor == other.kor && this->eng == other.eng) {
            return this->m > other.m;
        }
        if (this->kor == other.kor) {
            return this->eng < other.eng;
        }
        return this->kor > other.kor;
    }
};

int n;
vector<Student> v;

int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int kor;
        int eng;
        int m;
        cin >> name >> kor >> eng >> m;
        v.push_back(Student(name, kor, eng, m));
    }

    sort(v.begin(), v.end());

    // 정렬된 학생 정보에서 이름만 출력
    for (int i = 0; i < n; i++) {
        cout << v[i].name << '\n';
    }
}

/*
class STUDENT {
public:
	string name;
	int korean;
	int english;
	int math;

	STUDENT(string name, int a, int b, int c) {
		this->name = name;
		korean = a;
		english = b;
		math = c;
	}

	bool operator < (STUDENT& b) {
		if (korean == b.korean && english == b.english && math == b.math)
			return name < b.name;
		if (korean == b.korean && english == b.english)
			return math > b.math;
		if(korean == b.korean)
			return english < b.english;
		return korean > b.korean;
	}

};

int main() {
	int n;
	cin >> n;

	vector<STUDENT> v;

	for (int i = 0; i < n; i++) {
		string name;
		int a, b, c;
		cin >> name >> a >> b >> c;
		v.push_back(STUDENT(name, a, b, c));
	}

	sort(v.begin(), v.end());

	for (auto it : v) {
		cout << it.name << endl;
	}

}
*/