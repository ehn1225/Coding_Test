//DFS/BFS - BFS 예제
#include <bits/stdc++.h>
using namespace std;

int main() {
	bool graph[][9] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0, 0, 1},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0, 1},
		{0, 1, 0, 0, 0, 0, 0, 1, 0}
	};

	bool visited[9] = { 0, };

	int start = 1;
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << '\n';

		for (int i = 1; i < 9; i++) {
			if (graph[node][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}

}