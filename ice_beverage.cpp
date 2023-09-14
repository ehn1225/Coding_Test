//DFS/BFS 3 음료수 얼려먹기
#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[1000][1000] = { 0, };

// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool dfs(int x, int y) {
	// 주어진 범위를 벗어나는 경우에는 즉시 종료
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}
	// 현재 노드를 아직 방문하지 않았다면
	if (graph[x][y] == 0) {
		// 해당 노드 방문 처리
		graph[x][y] = 1;
		// 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	// N, M을 공백을 기준으로 구분하여 입력 받기
	cin >> n >> m;
	// 2차원 리스트의 맵 정보 입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	// 모든 노드(위치)에 대하여 음료수 채우기
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 현재 위치에서 DFS 수행
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}
	cout << result << '\n'; // 정답 출력 
}


/*
int dx[] = {0, -1, 0, 1};
int dy[] = { 1, 0, -1, 0 };

bool Check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	if(graph[x][y] == 1)
		return false;
	else
		return true;

}

void dfs(int x, int y) {
	graph[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (Check(nx, ny)) {
			dfs(nx, ny);
		}
	}

}

int main() {
	cin >> n >> m;

	cin.ignore();

	for (int i = 0; i < n; i++) {
		string tmp;
		getline(cin, tmp);
		for (int j = 0; j < m; j++) {
			graph[i][j] = tmp[j] - '0';
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] != 0) continue;
			dfs(i, j);
			result++;
		}
	}
	cout << result << endl;
}
*/
/*
	//배열 출력용
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
*/