//그래프 이론 문제 - 44 행성 터널
//백준 2887
#include <bits/stdc++.h>
using namespace std;

int FindParent(vector<int>& parent, int x) {
	if (parent[x] != x) {
		parent[x] = FindParent(parent, parent[x]);
	}
	return parent[x];
}

void UnionParent(vector<int>& parent, int a, int b) {
	a = FindParent(parent, a);
	b = FindParent(parent, b);
	
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}


int main() {
	int n;
	cin >> n;

	vector<int> parent(n + 1);
	for (int i = 0; i < n + 1; i++) {
		parent[i] = i;
	}

	vector<pair<int, int>> x;
	vector<pair<int, int>> y;
	vector<pair<int, int>> z;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a, i + 1 });
		y.push_back({ b, i + 1 });
		z.push_back({ c, i + 1 });
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	vector<pair<int, pair<int, int>>> edge;
	for (int i = 0; i < n - 1; i++) {
		edge.push_back({ x[i + 1].first - x[i].first, {x[i].second, x[i + 1].second} });
		edge.push_back({ y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second} });
		edge.push_back({ z[i + 1].first - z[i].first, {z[i].second, z[i + 1].second} });
	}

	sort(edge.begin(), edge.end());
	int mst = 0;
	for (int i = 0; i < edge.size(); i++) {
		int cost = edge[i].first;
		int src = edge[i].second.first;
		int dst = edge[i].second.second;

		if (FindParent(parent, src) != FindParent(parent, dst)) {
			UnionParent(parent, src, dst);
			mst += cost;
		}
	}

	cout << mst << '\n';

}