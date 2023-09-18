//우선순위 큐 다익스트라 알고리즘
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main() {
	int n, m; //n : 노드의 개수, m : 간선의 개수
	int start; //출발 노드

	cin >> n >> m;
	cin >> start;

	vector<pair<int, int>> v[1001];
	int distance[1001];

	for (int i = 0; i < n+1; i++) {
		distance[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		int src, dst, weight;
		cin >> src >> dst >> weight;
		v[src].push_back(make_pair(dst, weight));
	}

	//다익스트라 알고리즘
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, start); //출발노드의 가중치는 0	
	distance[start] = 0;

	while (!pq.empty()) {
		int weight = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (distance[node] < weight) continue;
		for (auto it : v[node]) {
			int new_node = it.first;
			int new_weight = it.second;
			int sum_weight = weight + new_weight;
			if (distance[new_node] > sum_weight) {
				distance[new_node] = sum_weight;
				pq.emplace(-sum_weight, new_node);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << distance[i] << " ";

}