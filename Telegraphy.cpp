//최단경로 - 3 전보
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int distanceArr[30001];
vector<pair<int, int>> maps[30001];

int main() {
	int n, m, c;
	cin >> n >> m >> c;

	for (int i = 0; i < m; i++) {
		int src, dst, weight;
		cin >> src >> dst >> weight;
		maps[src].push_back(make_pair(dst, weight));
	}

	fill(distanceArr, distanceArr + 30001, INF);

	//다익스트라
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, c);
	distanceArr[c] = 0;
	
	while (!pq.empty()) {
		int node = pq.top().second;
		int weight = -pq.top().first;
		pq.pop();
		if (weight > distanceArr[node]) continue;

		for (int i = 0; i < maps[node].size(); i++) {
			int next = maps[node][i].first;
			int next_weight = maps[node][i].second; 
			int weight_sum = weight + next_weight;
			if (weight_sum < distanceArr[next]) {
				distanceArr[next] = weight_sum;
				pq.emplace(-weight_sum, next);
			}
		}
	}
	int max_time = 0;
	int node_count = 0;
	for (int i = 1; i <= n; i++) {
		if (i == c) continue; // or 마지막에 node_count - 1 : 시작 노드 제외하기 위함
		if (distanceArr[i] != INF) {
			node_count++;
			max_time = max(max_time, distanceArr[i]);
		}
	}
	cout << node_count << " " << max_time << endl;
}