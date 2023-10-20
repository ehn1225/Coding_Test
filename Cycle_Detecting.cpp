//서로소 집합 알고리즘을 이용한 사이클 탐지
#include <bits/stdc++.h>
using namespace std;

int FindParent(vector<int>& parent, int x) {
	if (parent[x] != x)
		parent[x] = FindParent(parent, parent[x]);	//경로압축기법
	return parent[x];
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
	int n, m;	//n : 노드의 개수, m : Union 개수
	cin >> n >> m;

	vector<int> parent(n + 1);
	for (int i = 1; i < n + 1; i++)
		parent[i] = i;

	bool cycle = false;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		if (FindParent(parent, a) != FindParent(parent, b)) {
			UnionParent(parent, a, b);
		}
		else {
			cycle = true;
		}
	}

	if (cycle)
		cout << "A cycle has occurred.\n";
	else
		cout << "No cycle occurred.\n";

}