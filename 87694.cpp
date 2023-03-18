//Programmers 87694 : 깊이/너비 우선 탐색(DFS/BFS) - 아이템 줍기
#include <bits/stdc++.h>
using namespace std;

int maps[101][101] = {0, };
int xMax = 0, yMax = 0;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void PrintMap(){
    for(int i = yMax; i >-1; i--){
        for(int j = 0; j < xMax+1; j++){
            cout << maps[i][j];
        }
        cout << endl;
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    //2배 확대 및 직사각형 그리기
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    for(auto it : rectangle){
        int Xstart = it[0] * 2;
        int Ystart = it[1] * 2;
        int Xend = it[2] * 2;
        int Yend = it[3] * 2;
        if(xMax < Xend) xMax = Xend;
        if(yMax < Yend) yMax = Yend;
        
        for(int i = Ystart; i <= Yend; i++){//rows
            for(int j =Xstart; j <= Xend; j++){//cols
                maps[i][j] = 1;
            }
        }
    }
    
    // 직사각형의 내부 0 fill
    for (int i = 0; i < rectangle.size(); i++){
        int x1 = rectangle[i][0]*2, y1 = rectangle[i][1]*2;
        int x2 = rectangle[i][2]*2, y2 = rectangle[i][3]*2;
        for (int y = y1 + 1; y < y2; y++){
            for (int x = x1 + 1; x < x2; x++){
                maps[y][x] = 0;
            }
        }
    }
    
    //PrintMap();
    
    queue <pair<int, int>> q;
    q.emplace(characterX, characterY);
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if(x == itemX && y == itemY)
           break;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (maps[ny][nx] == 1) {
                q.emplace(nx, ny);
                maps[ny][nx] = maps[y][x] + 1;
            }
        }
    }  
    answer =  maps[itemY][itemX] / 2;
    return answer;
}