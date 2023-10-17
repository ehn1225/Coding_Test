//그래프 이론 문제 - 42 탑승구
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

using namespace std;

// 탑승구의 개수와 비행기의 개수
int g, p;
int parent[100001]; // 부모 테이블 초기화

// 특정 원소가 속한 집합을 찾기
int findParent(int x) {
	// 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main(void) {
	cin >> g >> p;

	// 부모 테이블상에서, 부모를 자기 자신으로 초기화
	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}

	int result = 0;
	for (int i = 0; i < p; i++) {
		int x;
		cin >> x;
		int root = findParent(x); // 현재 비행기의 탑승구의 루트 확인
		if (root == 0) break; // 현재 루트가 0이라면, 종료
		unionParent(root, root - 1); // 그렇지 않다면 바로 왼쪽의 집합과 합치기
		result += 1;
	}

	cout << result << '\n';
}

/*
int FindParent(int* parent, int n) {
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

int main() {
	int g, p;
	cin >> g >> p;

	int gate[100001];
	for (int i = 0; i <= g; i++) {
		gate[i] = i;
	}

	int result = 0;
	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;

		int pos = gate[a];
		if (pos == 0) {
			break;
		}
		else {
			UnionParent(gate, pos, pos - 1);
			result++;
		}

	}

	cout << result << endl;

}
*/

/*
//아쉽게도 오답. 시간을 초월해버려서 틀린 것으로 추정
int main() {
	int g, p;
	cin >> g >> p;
	priority_queue<int> pq;
	vector<int> planes;

	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}

	int gates[100001] = { 0, };

	int result = 0;
	while (!pq.empty()) {
		int gate = pq.top();
		pq.pop();

		bool isFull = true;
		for (int pos = gate; pos > 0; pos--) {
			if (gates[pos] == 0) {
				gates[pos] = 1;
				isFull = false;
				result++;
				break;
			}				
		}
		if (isFull) {
			break;
		}
	}

	cout << result << endl;
}
*/