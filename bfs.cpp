#include <bits/stdc++.h>
using namespace std;

int main() {
	bool visited[9] = { 0, };
	vector<int> graph[9];
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);
	graph[2].push_back(1);
	graph[2].push_back(7);
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);
	graph[4].push_back(3);
	graph[4].push_back(5);
	graph[5].push_back(3);
	graph[5].push_back(4);
	graph[6].push_back(7);
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);
	graph[8].push_back(1);
	graph[8].push_back(7);

	queue <int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int value = q.front();
		q.pop();
		cout << value << " ";
		for (int i = 0; i < graph[value].size(); i++) {
			if (visited[graph[value][i]] == false) {
				visited[graph[value][i]] = true;
				q.push(graph[value][i]);
			}
		}
	}

}