//그래프 이론 문제 - 44 행성 터널
#include <bits/stdc++.h>
using namespace std;

// 노드의 개수
int n;
int parent[100001]; // 부모 테이블 초기화
// 모든 간선을 담을 리스트와, 최종 비용을 담을 변수
vector<pair<int, pair<int, int> > > edges;
int result;

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
	cin >> n;

	// 부모 테이블상에서, 부모를 자기 자신으로 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	vector<pair<int, int> > x;
	vector<pair<int, int> > y;
	vector<pair<int, int> > z;

	// 모든 노드에 대한 좌표 값 입력받기
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a, i });
		y.push_back({ b, i });
		z.push_back({ c, i });
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	// 인접한 노드들로부터 간선 정보를 추출하여 처리
	for (int i = 0; i < n - 1; i++) {
		// 비용순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정
		edges.push_back({ x[i + 1].first - x[i].first, {x[i].second, x[i + 1].second} });
		edges.push_back({ y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second} });
		edges.push_back({ z[i + 1].first - z[i].first, {z[i].second, z[i + 1].second} });
	}

	// 간선을 비용순으로 정렬
	sort(edges.begin(), edges.end());

	// 간선을 하나씩 확인하며
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		// 사이클이 발생하지 않는 경우에만 집합에 포함
		if (findParent(a) != findParent(b)) {
			unionParent(a, b);
			result += cost;
		}
	}

	cout << result << '\n';
}

/*

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

class PLANET {
public:
	int planet_num;
	int x;
	int y;
	int z;
	PLANET(int a, int b, int c, int d) {
		x = a;
		y = b;
		z = c;
		planet_num = d;
	}
};
bool compare(const pair<int, pair<PLANET, PLANET>> &a, const pair<int, pair<PLANET, PLANET>>& b) {
	return a.first < b.first;
}
int main() {
	int n;
	cin >> n;
	int parent[100001];
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	vector<PLANET> planets;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		planets.push_back(PLANET(x, y, z, i+1));
	}

	vector<pair<int, pair<PLANET, PLANET>>> tunnels;

	//it works, but it is not efficient;
	for (PLANET a : planets) {
		for (PLANET b : planets) {
			if (a.x == b.x && a.y == b.y && a.z == b.z) continue;
			int cost = min(abs(a.x - b.x), min(abs(a.y - b.y), abs(a.z - b.z)));
			tunnels.push_back({ cost, {a, b}});
		}
	}

	sort(tunnels.begin(), tunnels.end(), compare);

	int min_cost = 0;
	for (int i = 0; i < tunnels.size(); i++) {
		int cost = tunnels[i].first;
		PLANET a = tunnels[i].second.first;
		PLANET b = tunnels[i].second.second;

		if (FindParent(parent, a.planet_num) != FindParent(parent, b.planet_num)) {
			UnionParent(parent, a.planet_num, b.planet_num);
			min_cost += cost;
		}
	}

	cout << min_cost << endl;

}
*/