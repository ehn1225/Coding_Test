//그래프 이론 문제 - 41 여행 계획
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
		parent[a] = b;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> parent(n + 1);
	for (int i = 0; i < n + 1; i++) {
		parent[i] = i;
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < n+1; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				if (FindParent(parent, i) != FindParent(parent, j)) {
					UnionParent(parent, i, j);
				}
			}
		}
	}

	vector<int> plan;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		plan.push_back(a);
	}

	bool answer = true;
	for (int i = 0; i < m-1; i++) {
		if (FindParent(parent, plan[i]) != FindParent(parent, plan[i+1])) {
			answer = false;
		}
	}

	cout << ((answer) ? "YES" : "NO") << '\n';


}