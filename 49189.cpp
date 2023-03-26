//Programmers 49189 : 그래프 - 가장 먼 노드
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define SIZE 20001

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int dist[SIZE];
    vector<pair<int, int>> segment[SIZE];
    
    for(int i = 0; i <= n; i++){
        dist[i] = INF;
    }
    
    for(int i = 0; i < edge.size(); i++){       //양방향 연결. 각 간선의 가중치는 1
        segment[edge[i][0]].push_back(make_pair(edge[i][1], 1));
        segment[edge[i][1]].push_back(make_pair(edge[i][0], 1));
    }
    
    priority_queue<pair<int, int>> pq;      //<가중치, 노드번호> 순
    pq.emplace(0, 1);                       //1번 노드 자신의 가중치는 0
    dist[1] = 0;
    int max = 0;
    
    while(!pq.empty()){
        int w = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if(dist[current] < w){
            continue;
        }
        
		for (int i = 0; i < segment[current].size(); i++) {
			int next = segment[current][i].first;
			int nextW = w + 1;
			if (nextW < dist[next]) {
				dist[next] = nextW;
                if(max < nextW){
                    max = nextW;
                } 
				pq.push(make_pair(-nextW, next));
			}
		}
    }
    
    for(int i = 1; i <= n; i++)
        if(dist[i] == max) answer++;

    return answer;
}