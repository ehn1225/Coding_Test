//구현 문제 - 12 기둥과 보 설치
//프로그래머스 60061
//일반적인 2차원 배열로 할 경우, 기둥 좌표의 왼쪽에, 보의 위쪽에 그림이 그려진다.
#include <bits/stdc++.h>
using namespace std;

bool possible(vector<vector<int>> answer) {
    for (int i = 0; i < answer.size(); i++) {
        int x = answer[i][0];
        int y = answer[i][1];
        int stuff = answer[i][2];

        if (stuff == 0) {//기둥
            bool check = false;
            if (y == 0)
                check = true;

            for (int j = 0; j < answer.size(); j++) {
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    check = true;
                if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    check = true;
                if (x == answer[j][0] && y - 1== answer[j][1] && 0 == answer[j][2])
                    check = true;
            }

            if (!check) return false;
        
        }
        else if (stuff == 1) {//보
            bool check = false;
            bool left = false;
            bool right = false;

            for (int j = 0; j < answer.size(); j++) {
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    left = true;
                if (x + 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    right = true;
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
                if (x + 1 == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
            }

            if (left && right) check = true;
            if (!check) return false;
        }
    }

    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (auto frameUnit : build_frame) {
        int x = frameUnit[0];
        int y = frameUnit[1];
        int stuff = frameUnit[2];
        int operate = frameUnit[3];
        if (operate == 0) { // 삭제하는 경우
            // 일단 삭제를 해 본 뒤에
            int index = 0;
            for (int j = 0; j < answer.size(); j++) {
                if (x == answer[j][0] && y == answer[j][1] && stuff == answer[j][2]) {
                    index = j;
                }
            }
            vector<int> erased = answer[index];
            answer.erase(answer.begin() + index);
            if (!possible(answer)) { // 가능한 구조물인지 확인
                answer.push_back(erased); // 가능한 구조물이 아니라면 다시 설치
            }
        }
        if (operate == 1) { // 설치하는 경우
            // 일단 설치를 해 본 뒤에
            answer.push_back({x, y, stuff});
            if (!possible(answer)) { // 가능한 구조물인지 확인
                answer.pop_back(); // 가능한 구조물이 아니라면 다시 제거, Delete last element
            }
        }
    }
    // 정렬된 결과를 반환
    sort(answer.begin(), answer.end());

    return answer;
}
int main() {
    int n = 5;
    vector<vector<int>> build_frame = {
        {1, 0, 0, 1},
        {1, 1, 1, 1},
        {2, 1, 0, 1},
        {2, 2, 1, 1},
        {5, 0, 0, 1},
        {5, 1, 0, 1},
        {4, 2, 1, 1},
        {3, 2, 1, 1}
    };

    vector<vector<int>> answer = solution(n, build_frame);
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[0].size(); j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}