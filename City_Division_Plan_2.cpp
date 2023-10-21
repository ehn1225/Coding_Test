//그래프 이론 - 3 도시 분할 계획
#include <bits/stdc++.h>
using namespace std;

int FindParent(vector<int>& parent, int x) {
	if (parent[x] != x)
		parent[x] = FindParent(parent, parent[x]);
	return parent[x];
}

void UnionParent(vector<int>& parent, int a, int b) {
	a = FindParent(parent, a);
	b = FindParent(parent, b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> parent(n + 1);
	for (int i = 1; i < n + 1; i++)
		parent[i] = i;

	vector<pair<int, pair<int, int>>> edge;
	for (int i = 0; i < m; i++) {
		int src, dst, cost;
		cin >> src >> dst >> cost;
		edge.push_back({ cost, {src, dst} });
	}

	sort(edge.begin(), edge.end());

	int answer = 0;
	int max_cost = 0;
	for (int i = 0; i < edge.size(); i++) {
		int src = edge[i].second.first;
		int dst = edge[i].second.second;
		int cost = edge[i].first;

		if (FindParent(parent, src) != FindParent(parent, dst)) {
			UnionParent(parent, src, dst);
			answer += cost;
			max_cost = max(max_cost, cost);
		}
	}

	cout << answer - max_cost << '\n';



}