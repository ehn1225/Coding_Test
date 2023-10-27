//최단 경로 문제 - 40 숨바꼭질
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> graph[20001];
	vector<int> d(n + 1, INF);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	//거리가 1이기에 다익스트라 알고리즘과 더불어 BFS 사용 가능
	queue<int> q;
	q.push(1);
	d[1] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int next : graph[node]) {
			int nextCost = d[node] + 1;
			if (d[next] > nextCost) {
				d[next] = nextCost;
				q.push(next);
			}
		}
	}

	int count = 0;
	int dist = 0;
	int pos = 0;
	for (int i = 1; i < n + 1; i++) {
		if (d[i] > dist) {
			dist = d[i];
			pos = i;
			count = 1;
		}
		else if (d[i] == dist) {
			count++;
		}
	}

	cout << pos << ' ' << dist << ' ' << count << '\n';

}