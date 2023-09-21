//백준 1197 - 최소 스패닝 트리
#include <bits/stdc++.h>
using namespace std;

int FindParent(int *parent, int n) {
	if (parent[n] != n)
		parent[n] = FindParent(parent, parent[n]);
	return parent[n];
}

void UnionParent(int* parent, int a, int b) {
	a = FindParent(parent, a);
	b = FindParent(parent, b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

class EDGE {
public:
	int start;
	int end;
	int weight;
	EDGE(int src, int dst, int weight) {
		this->start = src;
		this->end = dst;
		this->weight = weight;
	}
	bool operator < (EDGE& b) {
		return weight < b.weight;
	}
};

int main() {
	int v, e;
	vector<EDGE> list;
	int parent[10001];

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		EDGE tmp = EDGE(a, b, c);
		list.push_back(tmp);
	}

	for (int i = 1; i < v + 1; i++)
		parent[i] = i;

	sort(list.begin(), list.end()); //오름차순 정렬

	int cost = 0;
	for (auto it : list) {
		if (FindParent(parent, it.start) != FindParent(parent, it.end)) {
			UnionParent(parent, it.start, it.end);
			cost += it.weight;
		}
	}

	cout << cost << endl;

}