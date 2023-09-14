//구현 - 상하좌우(예제 4-1)
#include <bits/stdc++.h>
using namespace std;

// N을 입력받기
int n;
string plans;
int x = 1, y = 1;

// L, R, U, D에 따른 이동 방향 
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char moveTypes[4] = { 'L', 'R', 'U', 'D' };

int main(void) {
    cin >> n;
    cin.ignore(); // 버퍼 비우기 
    getline(cin, plans);
    // 이동 계획을 하나씩 확인
    for (int i = 0; i < plans.size(); i++) {
        char plan = plans[i];
        // 이동 후 좌표 구하기 
        int nx = -1, ny = -1;
        for (int j = 0; j < 4; j++) {
            if (plan == moveTypes[j]) {
                nx = x + dx[j];
                ny = y + dy[j];
            }
        }
        // 공간을 벗어나는 경우 무시 
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        // 이동 수행 
        x = nx;
        y = ny;
    }
    cout << x << ' ' << y << '\n';
    return 0;
}

/*
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

bool check(int x, int y, int n) {
    if(x < 1 || x > n || y < 1 || y > n) return false;
    return true;
}

int main() {
	int n;
	int x = 1, y = 1;
    string tmp;

    cin >> n;
    cin.ignore();
    getline(cin, tmp);
	
    vector<string> tmp2 = split(tmp, ' ');

    //L, R, U, D에 따른 이동 방향
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    char move_types[] = { 'L', 'R', 'U', 'D' };

    for (auto it : tmp2) {
        int nx = 0;
        int ny = 0;

        for (int j = 0; j < 4; j++) {
            if (it[0] == move_types[j]) {
				nx = dx[j];
				ny = dy[j];
			}
		}

        if(check(x + nx, y + ny, n)) {
			x += nx;
			y += ny;
		}
    }

    cout << x << " " << y << "\n";

}

*/
