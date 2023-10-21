//그래프 이론 - 크루스칼 알고리즘 Kruskal Algorithm
#include <bits/stdc++.h>
using namespace std;

int FindParent(int* parent, int x) {
	if (parent[x] != x)
		parent[x] = FindParent(parent, parent[x]);
	return parent[x];
}

void UnionParent(int* parent, int a, int b) {
	a = FindParent(parent, a);
	b = FindParent(parent, b);
	
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, pair<int, int>>> v;
	int parent[100];
	for (int i = 0; i < 100; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		int src, dst, cost;
		cin >> src >> dst >> cost;
		v.push_back({ cost, {src, dst} });
	}

	sort(v.begin(), v.end());

	int totalCost = 0;
	for (int i = 0; i < v.size(); i++) {
		int src = v[i].second.first;
		int dst = v[i].second.second;
		int cost = v[i].first;

		if (FindParent(parent, src) != FindParent(parent, dst)) {
			UnionParent(parent, src, dst);
			totalCost += cost;
		}
	}

	cout << totalCost << '\n';

}