//최단 경로 - 다익스트라(Dijkstra)
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9


int main() {
	int n, m, start;

	cin >> n >> m >> start;	//노드의 개수, 간선의 개수, 시작 노드를 입력받기,
	vector<int> d(n + 1, INF);
	vector<pair<int, int>> graph[10];
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	d[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int weight = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (d[node] < weight) continue;

		for (auto it : graph[node]) {
			int next = it.first;
			int cost = weight + it.second;
			if (cost < d[next]) {
				d[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}


	for (int i = 1; i < n + 1; i++) {
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}

}


//간단한 다익스트라 알고리즘 구현. 빅오의 n^2 시간 소요
/*
#define MAX_NODE 100
int n, m, start;
vector<pair<int, int>> graph[MAX_NODE+1];
vector<int> d(MAX_NODE + 1, INF);
vector<bool> visited(MAX_NODE + 1, 0);

int getSmallestNode() {
	int min_value = 1e9;
	int idx = 0;
	for (int i = 1; i < n+1; i++) {
		if (d[i] < min_value && visited[i] == false) {
			idx = i;
			min_value = d[i];
		}
	}
	return idx;

}

void Dijkstra(int start) {
	d[start] = 0;
	visited[start] = true;
	for (int i = 0; i < graph[start].size(); i++) {
		d[graph[start][i].first] = graph[start][i].second;
	}

	for (int i = 0; i < n - 1; i++) {
		int now = getSmallestNode();
		visited[now] = true;
		for (int j = 0; j < graph[now].size(); j++) {
			int cost = d[now] + graph[now][j].second;
			if (cost < d[graph[now][j].first])
				d[graph[now][j].first] = cost;
		}
	}
}
int main() {
	cin >> n >> m >> start;	//노드의 개수, 간선의 개수, 시작 노드를 입력받기,

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	Dijkstra(start);

	for (int i = 1; i < n + 1; i++) {
		if(d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}

}
*/