//서로소 집합 알고리즘
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

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		UnionParent(parent, a, b);
	}

	cout << "각 원소가 속한 집합 : ";
	for (int i = 1; i < n + 1; i++)
		cout << FindParent(parent, i) << ' ';

	cout << '\n' << "부모 테이블 : ";
	for (int i = 1; i < n + 1; i++)
		cout << parent[i] << ' ';


}