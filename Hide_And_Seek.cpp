//최단 경로 문제 - 40 숨바꼭질
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

// 노드의 개수(N), 간선의 개수(M)
int n, m;
// 시작 노드를 1번 헛간으로 설정
int start = 1;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트를 만들기
vector<pair<int, int> > graph[20001];
// 최단 거리 테이블 만들기
int d[20001];

void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	// 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) { // 큐가 비어있지 않다면
		// 가장 최단 거리가 짧은 노드에 대한 정보를 꺼내기
		int dist = -pq.top().first; // 현재 노드까지의 비용 
		int now = pq.top().second; // 현재 노드
		pq.pop();
		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시
		if (d[now] < dist) continue;
		// 현재 노드와 연결된 다른 인접한 노드들을 확인
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			// 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
}

int main(void) {
	cin >> n >> m;

	// 모든 간선 정보를 입력받기
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		// a번 노드와 b번 노드의 이동 비용이 1이라는 의미(양방향)
		graph[a].push_back({ b, 1 });
		graph[b].push_back({ a, 1 });
	}

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill(d, d + 20001, INF);

	// 다익스트라 알고리즘을 수행
	dijkstra(start);

	// 가장 최단 거리가 먼 노드 번호(동빈이가 숨을 헛간의 번호)
	int maxNode = 0;
	// 도달할 수 있는 노드 중에서, 가장 최단 거리가 먼 노드와의 최단 거리
	int maxDistance = 0;
	// 가장 최단 거리가 먼 노드와의 최단 거리와 동일한 최단 거리를 가지는 노드들의 리스트
	vector<int> result;

	for (int i = 1; i <= n; i++) {
		if (maxDistance < d[i]) {
			maxNode = i;
			maxDistance = d[i];
			result.clear();
			result.push_back(maxNode);
		}
		else if (maxDistance == d[i]) {
			result.push_back(i);
		}
	}

	cout << maxNode << ' ' << maxDistance << ' ' << result.size() << '\n';
}

/*

vector<int> maps[20001];
int d[20001] = { 0, };
bool compareFirstElement(const pair<int, int>& p, int value) {
	return p.first < value;
}
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		maps[a].push_back(b);
		maps[b].push_back(a);

	}

	fill(d, d + 20001, INF);

	priority_queue<pair<int, int>> pq;
	pq.emplace(0, 1);
	
	d[1] = 0;
	while (!pq.empty()) {
		int weight = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (weight > d[node])
			continue;

		for (int i = 0; i < maps[node].size(); i++) {
			int newNode = maps[node][i];
			int cost = d[node] + 1;
			if (cost < d[newNode]) {
				d[newNode] = cost;
				pq.emplace(-cost, newNode);
			}
		}
	}

	int maxNode = 0;
	int maxDistance = 0;
	vector<int> result;
	for (int i = 1; i < n+1; i++) {
		if (maxDistance < d[i]) {
			maxDistance = d[i];
			maxNode = i;
			result.clear();
			result.push_back(i);
		}
		else if (maxDistance == d[i]) {
			result.push_back(i);
		}
	}
	cout << maxNode << " " << maxDistance << " " << result.size() << endl;

	//위의 기능과 동일한 동작을 수행하나, 조금 비효율적....
	//vector<pair<int, int>> solution;
	//for (int i = 1; i <= n; i++) {
	//	solution.push_back({ d[i], i });
	//}
	//sort(solution.begin(), solution.end(), compare);
	//
	//int maxdist = solution[n - 1].first;
	//
	//// lower_bound를 사용하여 찾기
	//vector<pair<int, int>>::iterator first_hit = lower_bound(solution.begin(), solution.end(), maxdist, compareFirstElement);
	//int diff = count(d + 1, d + n + 1, maxdist);
	//
	//cout << first_hit->second << " " << maxdist << " " << diff << endl;
	
}
*/