//그래프 이론 - 3 도시 분할 계획
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

class SEGMENT{
public:
	int src;
	int dst;
	int weight;
	SEGMENT(int a, int b, int c){
		src = a;
		dst = b;
		weight = c;
	}
	bool operator < (SEGMENT& b) {
		return weight < b.weight;
	}
};

int main() {
	int n, m;
	vector<SEGMENT> v;
	int parent[100001];

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		SEGMENT temp = SEGMENT(a, b, c);
		v.push_back(temp);
	}

	for (int i = 1; i < n +1 ; i++)
		parent[i] = i;

	sort(v.begin(), v.end());

	int result = 0;
	int max_weight = 0;

	for (auto edge : v) {
		if (FindParent(parent, edge.src) != FindParent(parent, edge.dst)) {
			UnionParent(parent, edge.src, edge.dst);
			result += edge.weight;
			max_weight = edge.weight;
		}
	}

	result -= max_weight;

	cout << result << endl;

}