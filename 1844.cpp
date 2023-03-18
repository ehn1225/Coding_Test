//Programmers 1844 : 깊이/너비 우선 탐색(DFS/BFS) - 게임 맵 최단거리
#include<bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m;
bool visited[101][101] = {0, };
int bfs_sum[101][101] = {0, };

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int solution(vector<vector<int>> maps){
    m = maps.size();    //행의 개수
    n = maps[0].size(); //열의 개수
    
    queue <pair<int,int>> q;
    q.emplace(0, 0);
    visited[0][0] = true;
    bfs_sum[0][0] = 1;
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        //if(x == n-1 && y == m-1) return bfs_sum[m-1][n-1];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && !visited[ny][nx] && maps[ny][nx]) {
                visited[ny][nx] = true;
                q.emplace(nx, ny);
                bfs_sum[ny][nx] = bfs_sum[y][x] + 1;
            }
        }
        
    }
    if(!bfs_sum[m-1][n-1])
        return -1;
    else
        return bfs_sum[m-1][n-1];

}