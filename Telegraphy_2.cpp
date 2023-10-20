//최단 경로 - 3 전보
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
	int n, m, c;
	cin >> n >> m >> c;

	vector<pair<int, int>> graph[30001];
	vector<int> d(30001, INF);

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({ y, z });
	}

	//다익스트라 알고리즘 수행
	d[c] = 0;
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, c);

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;

		for (auto it : graph[now]) {
			int next = it.first;
			int cost = dist + it.second;
			if (cost < d[next]) {
				d[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}

	int city = 0, time = 0;
	for (int i = 1; i < n+1; i++) {
		if (i == c) continue; //시작 노드는 도시 개수 카운트에서 제외
		if (d[i] != INF) {
			city++;
			time = max(time, d[i]);
		}
	}

	cout << city << " " << time << '\n';


}