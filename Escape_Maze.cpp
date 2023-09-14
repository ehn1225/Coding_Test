//DFS/BFS - �̷� Ż�� 4
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[201][201];

// �̵��� �� ���� ���� ���� (��, ��, ��, ��) 
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int x, int y) {
	// ť(Queue) ������ ���� queue ���̺귯�� ��� 
	queue<pair<int, int> > q;
	q.push({ x, y });
	// ť�� �� ������ �ݺ��ϱ� 
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// ���� ��ġ���� 4���� ���������� ��ġ Ȯ��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// �̷� ã�� ������ ��� ��� ����
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// ���� ��� ����
			if (graph[nx][ny] == 0) continue;
			// �ش� ��带 ó�� �湮�ϴ� ��쿡�� �ִ� �Ÿ� ���
			if (graph[nx][ny] == 1) {
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	// ���� ������ �Ʒ������� �ִ� �Ÿ� ��ȯ
	return graph[n - 1][m - 1];
}

int main(void) {
	// N, M�� ������ �������� �����Ͽ� �Է� �ޱ�
	cin >> n >> m;
	// 2���� ����Ʈ�� �� ���� �Է� �ޱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	// BFS�� ������ ��� ���
	cout << bfs(0, 0) << '\n';
	return 0;
}

/*
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

bool Check(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	if (graph[x][y] == 0)
		return false;
	else
		return true;
}

class EDGE {
public:
	int x;
	int y;
	int weight;
	EDGE();
	EDGE(int x, int y, int weight) {
		this->x = x;
		this->y = y;
		this->weight = weight;
	}
};

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	queue<EDGE> q;
	EDGE tmp = EDGE(0, 0, 1);
	q.push(tmp);
	graph[0][0] = 0;

	while (!q.empty()) {
		EDGE node = q.front();
		q.pop();
		if (node.x == n-1 && node.y == m-1) {
			cout << node.weight << endl;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			if (Check(nx, ny)) {
				graph[nx][ny] = 0;
				EDGE tmp2 = EDGE(nx, ny, node.weight + 1);
				q.push(tmp2);
			}
		}
	}
}
*/