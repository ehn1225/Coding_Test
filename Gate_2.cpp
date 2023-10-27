//그래프 이론 문제 - 42 탑승구
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
	int g, p;
	cin >> g >> p;

	vector<int> parent(g + 1);
	for (int i = 0; i < g + 1; i++) {
		parent[i] = i;
	}

	int answer = 0;
	for (int i = 0; i < p; i++) {
		int plane;
		cin >> plane;

		int result = FindParent(parent, plane);
		if (result == 0) {
			break;
		}
		else {
			//왼쪽 노드와 합침
			UnionParent(parent, result, result - 1);
			answer++;
		}
	}

	cout << answer << '\n';
}