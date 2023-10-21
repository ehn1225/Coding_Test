//그래프 이론 - 4 커리큘럼
#include <bits/stdc++.h>
using namespace std;
bool graph[501][501] = { 0, };

int main() {
	int n;
	cin >> n;
	//강의 시간, 선수 강의 배열
	vector<int> hours(n + 1, 0);
	vector<int> indegree(n + 1, 0);
	for (int i = 1; i < n+1; i++) {
		int hour, tmp;
		cin >> hour;
		cin >> tmp;
		while (tmp != -1) {
			indegree[i]++;
			graph[tmp][i] = true;
			cin >> tmp;
		}
		hours[i] = hour;
	}

	//result에 최대값을 갱신하는 방식
	queue<int> q;
	for (int i = 1; i < n + 1; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	vector<int> result(hours);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 1; i < n + 1; i++) {
			if (graph[node][i] == 1) {
				result[i] = max(result[i], result[node] + hours[i]);
				indegree[i]--;
				if (indegree[i] == 0) {
					q.push(i);
				}
			}
		}
	}

	for (int i = 1; i < n + 1; i++) {
		cout << result[i] << '\n';
	}

	//queue에 이전 단계의 최대 소요 시간과 새로 큐에 들어가는 노드 번호를 함께 넣는 방식
	/*
	queue<pair<int, int>> q;
	for (int i = 1; i < n+1; i++) {
		if (indegree[i] == 0)
			q.push({ i, 0 });
	}

	while (!q.empty()) {
		int node = q.front().first;
		int hour = q.front().second + hours[node];
		q.pop();
		cout << hour << '\n';

		for (int i = 1; i < n + 1; i++) {
			if (graph[node][i] == 1) {
				indegree[i]--;
				if (indegree[i] == 0) {
					q.push({ i, hour});
				}
			}
		}
	}
	*/

}