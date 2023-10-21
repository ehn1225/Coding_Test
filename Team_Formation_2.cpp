//그래프 이론 - 2 팀 결성
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
	for (int i = 0; i < n + 1; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int oper, a, b;
		cin >> oper >> a >> b;
		if (oper == 0) {
			UnionParent(parent, a, b);
		}
		else {
			if (FindParent(parent, a) == FindParent(parent, b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}

}