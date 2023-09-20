//그래프이론 - Union Find
#include <bits/stdc++.h>
using namespace std;

int parent[100] = {0, };

int FindParent(int *arr, int n) {
	if (arr[n] != n) {
		arr[n] = FindParent(arr, arr[n]); //경로 압축 기법 사용
	}
	return arr[n];
}
void UnionParent(int *arr, int a, int b) {
	a = FindParent(arr, a);
	b = FindParent(arr, b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	int v, e; // v : 노드 수, e : 간선 수(Union 수)
	cin >> v >> e;

	for (int i = 1; i < v + 1; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		UnionParent(parent, a, b);
	}

	cout << "The set to which each element belongs : ";
	for (int i = 1; i < v + 1; i++)
		cout << FindParent(parent, i) << " ";

	cout << endl << "Parent table content : ";
	for (int i = 1; i < v+1; i++)
		cout << parent[i] << " ";

}