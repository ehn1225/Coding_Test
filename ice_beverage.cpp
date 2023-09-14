//DFS/BFS 3 ����� ����Ա�
#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[1000][1000] = { 0, };

// DFS�� Ư�� ��带 �湮�ϰ� ����� ��� ���鵵 �湮
bool dfs(int x, int y) {
	// �־��� ������ ����� ��쿡�� ��� ����
	if (x <= -1 || x >= n || y <= -1 || y >= m) {
		return false;
	}
	// ���� ��带 ���� �湮���� �ʾҴٸ�
	if (graph[x][y] == 0) {
		// �ش� ��� �湮 ó��
		graph[x][y] = 1;
		// ��, ��, ��, ���� ��ġ�鵵 ��� ��������� ȣ��
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main() {
	// N, M�� ������ �������� �����Ͽ� �Է� �ޱ�
	cin >> n >> m;
	// 2���� ����Ʈ�� �� ���� �Է� �ޱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	// ��� ���(��ġ)�� ���Ͽ� ����� ä���
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// ���� ��ġ���� DFS ����
			if (dfs(i, j)) {
				result += 1;
			}
		}
	}
	cout << result << '\n'; // ���� ��� 
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
	//�迭 ��¿�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
*/