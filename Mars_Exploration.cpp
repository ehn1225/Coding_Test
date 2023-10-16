//최단 경로 문제 - 39 화성 탐사
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

//상우하좌
int dx[] = { -1, 0, 1, 0 };
int dy[] = {0, 1, 0, -1};

int main() {
	int t;
	cin >> t;

	// 전체 테스트 케이스(Test Case)만큼 반복
	for (int i = 0; i < t; i++) {
		// 노드의 개수를 입력받기
		int n;
		cin >> n;

		vector<vector<int>>graph(n, vector<int>(n));
		vector<vector<int>>d(n, vector<int>(n, INF));  //최단 거리 테이블을 모두 무한으로 초기화

		// 전체 맵 정보를 입력받기
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> graph[j][k];
			}
		}

		int x = 0, y = 0; // 시작 위치는 (0, 0)
        // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
        priority_queue<pair<int, pair<int, int> > > pq;
        pq.push({-graph[x][y], {0, 0}});
        d[x][y] = graph[x][y];

        // 다익스트라 알고리즘을 수행
        while (!pq.empty()) {
            // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
            int dist = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
            if (d[x][y] < dist) continue;
            // 현재 노드와 연결된 다른 인접한 노드들을 확인
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                // 맵의 범위를 벗어나는 경우 무시
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int cost = dist + graph[nx][ny];
                // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
                if (cost < d[nx][ny]) {
                    d[nx][ny] = cost;
                    pq.push({-cost, {nx, ny}});
                }
            }
        }
        cout << d[n - 1][n - 1] << '\n';
	}

}

/*
//이미 처리된 영역을 다시 계산할 경우 오류 발생.
int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		vector<int> v(n * n, INF);
		vector<vector<int>>maps(n, vector<int>(n));

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> maps[j][k];
			}
		}

		v[0] = maps[0][0];

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int idx = (j * n) + k;
				for (int l = 0; l < 4; l++) {
					int nx = j + dx[l];
					int ny = k + dy[l];
					int nidx = (nx * n) + ny;
					if (nx > -1 && nx < n && ny > -1 && ny < n) {
						v[idx] = min(v[idx], v[nidx] + maps[j][k]);
					}
				}

			}
		}

		cout << v[(n * n) - 1] << endl;

	}

}
*/