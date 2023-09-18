//�켱���� ť ���ͽ�Ʈ�� �˰���
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main() {
	int n, m; //n : ����� ����, m : ������ ����
	int start; //��� ���

	cin >> n >> m;
	cin >> start;

	vector<pair<int, int>> v[1001];
	int distance[1001];

	for (int i = 0; i < n+1; i++) {
		distance[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		int src, dst, weight;
		cin >> src >> dst >> weight;
		v[src].push_back(make_pair(dst, weight));
	}

	//���ͽ�Ʈ�� �˰���
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, start); //��߳���� ����ġ�� 0	
	distance[start] = 0;

	while (!pq.empty()) {
		int weight = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (distance[node] < weight) continue;
		for (auto it : v[node]) {
			int new_node = it.first;
			int new_weight = it.second;
			int sum_weight = weight + new_weight;
			if (distance[new_node] > sum_weight) {
				distance[new_node] = sum_weight;
				pq.emplace(-sum_weight, new_node);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << distance[i] << " ";

}