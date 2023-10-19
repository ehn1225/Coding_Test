//DFS/BFS - DFS 예제
#include <bits/stdc++.h>
using namespace std;

void dfs(bool graph[9][9], int node, bool* visited) {

	visited[node] = true;
	cout << node << '\n';

	for (int i = 1; i < 9; i++) {
		if (graph[node][i] == 1 && visited[i] == false) {
			dfs(graph, i, visited);
		}
	}

}

int main() {
	bool graph[9][9] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0, 0, 1},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0, 1},
		{0, 1, 0, 0, 0, 0, 0, 1, 0},
	};

	bool visited[9] = { 0, };

	dfs(graph, 1, visited);

}