//그래프 이론 문제 - 43 어두운 길
//MST 문제
#include <bits/stdc++.h>
using namespace std;

int FindParent(vector<int>& parent, int x) {
	if (x == parent[x]) return x;
	return parent[x] = FindParent(parent, parent[x]);
}

void UnionParent(vector<int>& parent, int a, int b) {
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

	vector<pair<int, pair<int, int>>> edge;
	vector<int> parent(n + 1);
	for (int i = 0; i < n + 1; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge.push_back({ z,{x, y} });
	}

	sort(edge.begin(), edge.end());

	int totalCost = 0;
	int mst = 0;
	for (int i = 0; i < m; i++) {
		int x = edge[i].second.first;
		int y = edge[i].second.second;
		int cost = edge[i].first;
		totalCost += cost;

		if (FindParent(parent, x) != FindParent(parent, y)) {
			UnionParent(parent, x, y);
			mst += cost;
		}
	}

	cout << totalCost - mst << '\n';

}