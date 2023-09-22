//그래프 이론 - 2 팀 결성
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
	int parent[100001]{ 0, };

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			UnionParent(parent, b, c);
		}
		else {
			if (FindParent(parent, b) != FindParent(parent, c)) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}


	}

}