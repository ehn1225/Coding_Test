//DFS/BFS - 15 특정 거리의 도시 찾기
//백준 18352
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<int> edge[300001];

int main() {
	int n, m, k, x;
	cin >> n >> m >> k >> x;

	vector<int> d(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}

	queue<int> q;
	d[x] = 0;
	q.push(x);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int it : edge[node]) {
			if (d[it] == -1) {
				d[it] = d[node] + 1;
				q.push(it);
			}
		}
	}

	int find = false;
	for (int i = 1; i < n + 1; i++) {
		if (d[i] == k) {
			cout << i << '\n';
			find = true;
		}
	}

	if (find == false)
		cout << -1 << '\n';

}

//다익스트라 코드
/*
int main() {
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	
	vector<int> d(n + 1, INF);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}

	queue<pair<int, int>> q;
	q.push({ 0, x });
	d[x] = 0;

	while (!q.empty()) {
		int node = q.front().second;
		int cost = -q.front().first;
		q.pop();

		if (d[node] < cost) continue;

		for (int it : edge[node]) {
			int newCost = cost + 1;
			if (d[it] > newCost) {
				d[it] = newCost;
				q.push({ -newCost, it });
			}
		}
	}
	int find = false;
	for (int i = 1; i < n + 1; i++) {
		if (d[i] == k) {
			cout << i << '\n';
			find = true;
		}
	}

	if (find == false)
		cout << -1 << '\n';

}
*/