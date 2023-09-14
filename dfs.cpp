#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> *graph, int v, int *visited) {
	visited[v] = 1;
	cout << v << " ";

	for (int i = 0; i < graph[v].size(); i++) {
		if (visited[graph[v][i]] == 0)
			dfs(graph, graph[v][i], visited);
	}
}

int main() {
	int visited[9] = { 0, };
	vector<int> graph[9];
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);
	graph[2].push_back(1);
	graph[2].push_back(7);
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);
	graph[4].push_back(3);
	graph[4].push_back(5);
	graph[5].push_back(3);
	graph[5].push_back(4);
	graph[6].push_back(7);
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);
	graph[8].push_back(1);
	graph[8].push_back(7);

	dfs(graph, 1, visited);
}