//간단한 다익스트라 알고리즘
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

class EDGE {
public:
	int src;
	int dst;
	int weight;
	EDGE(int src, int dst, int weight) {
		this->src = src;
		this->dst = dst;
		this->weight = weight;
	}
	bool operator < (EDGE& b) {
		return this->weight < b.weight;
	}
};

int GetShortestNode(vector<int> distance, vector<bool> visited) {
	int min = INF;
	int index = 0;

	for (int i = 0; i < distance.size(); i++) {
		if (distance[i] < min && visited[i] == false) {
			min = distance[i];
			index = i;
		}
	}
	return index;
}

int main() {
	int n, m; //n : 노드의 개수, m : 간선의 개수
	int start; //출발 노드
	
	cin >> n >> m;
	cin >> start;

	vector<EDGE> v;
	vector<bool> visited(n + 1, false);
	vector<int> distance(n + 1, INF);

	for (int i = 0; i < m; i++) {
		int src, dst, weight;
		cin >> src >> dst >> weight;
		EDGE tmp = EDGE(src, dst, weight);
		v.push_back(tmp);
	}

	//다익스트라 알고리즘
	distance[start] = 0;
	visited[start] = true;
	for (auto it : v) {
		if (it.src == start)
			distance[it.dst] = it.weight;
	}

	for (int i = 0; i < n - 1; i++) {
		int node = GetShortestNode(distance, visited);
		visited[node] = true;

		for (auto it : v) {
			if (it.src == node)
				distance[it.dst] = min(distance[it.dst], it.weight + distance[it.src]);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << distance[i] << " ";

}