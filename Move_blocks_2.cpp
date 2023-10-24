//DFS/BFS - 22 블록 이동하기
//프로그래머스 60063
#include <bits/stdc++.h>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int rdx[] = { -1, 1};
int rdy[] = { -1, 1};
class ROBOT {
public:
    int x1;
    int y1;
    int x2;
    int y2;
    int move_count;

    ROBOT(int x1, int y1, int x2, int y2,int c) {
       this->x1 = x1;
       this->y1 = y1;
       this->x2 = x2;
       this->y2 = y2;
       move_count = c;
    }
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();

    vector<vector<int> > newBoard(n + 2, vector<int>(n + 2, 1));
    vector<ROBOT> visited;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newBoard[i + 1][j + 1] = board[i][j];
        }
    }

    queue<ROBOT> q;
    ROBOT start(1, 1, 1, 2, 0);
    q.push(start);
    visited.push_back(start);

    while (!q.empty()) {
        ROBOT rbt = q.front();
        q.pop();

        if ((rbt.x1 == n  && rbt.y1 == n) || (rbt.x2 == n  && rbt.y2 == n)) {
            answer = rbt.move_count;
            break;
        }

        vector<ROBOT> movement;
        //상하좌우 이동
        for (int i = 0; i < 4; i++) {
            int nx1 = rbt.x1 + dx[i];
            int ny1 = rbt.y1 + dy[i];
            int nx2 = rbt.x2 + dx[i];
            int ny2 = rbt.y2 + dy[i];

            if (newBoard[nx1][ny1] == 1 || newBoard[nx2][ny2] == 1) continue;
            movement.push_back(ROBOT(nx1, ny1, nx2, ny2, rbt.move_count + 1));
        }

        //회전
        if (rbt.x1 == rbt.x2) {
            //로봇이 가로 상태일 때
            for (int i = 0; i < 2; i++) {
                int nx1 = rbt.x1 + rdx[i];
                int nx2 = rbt.x2 + rdx[i];

                if (newBoard[nx1][rbt.y1] == 0 && newBoard[nx2][rbt.y2] == 0) {
                    movement.push_back(ROBOT(rbt.x1, rbt.y1, nx1, rbt.y1, rbt.move_count + 1));
                    movement.push_back(ROBOT(rbt.x2, rbt.y2, nx2, rbt.y2, rbt.move_count + 1));
                }
            }
           
        }
        else {
            //로봇이 세로 상태일 때
            for (int i = 0; i < 2; i++) {
                int ny1 = rbt.y1 + rdy[i];
                int ny2 = rbt.y2 + rdy[i];

                if (newBoard[rbt.x1][ny1] == 0 && newBoard[rbt.x2][ny2] == 0) {
                    movement.push_back(ROBOT(rbt.x1, rbt.y1, rbt.x1, ny1, rbt.move_count + 1));
                    movement.push_back(ROBOT(rbt.x2, rbt.y2, rbt.x2, ny2, rbt.move_count + 1));
                }
            }

        }

        for (ROBOT nextMove : movement) {
            bool check = true;
            for (ROBOT vis : visited) {
                if (nextMove.x1 == vis.x1 && nextMove.y1 == vis.y1 && nextMove.x2 == vis.x2 && nextMove.y2 == vis.y2) {
                    check = false;
                    break;
                }
            }
            if (check) {
                q.push(nextMove);
                visited.push_back(nextMove);
            }

        }

    
    }

    return answer;
}

int main() {
    vector<vector<int>> board = { 
        {0,0,0,1,1},
        {0,0,0,1,0},
        {0,1,0,1,1},
        {1,1,0,0,1},
        {0,0,0,0,0}
    };

    cout << solution(board) << '\n'; //7이 정답

}