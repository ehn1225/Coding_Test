//최단 경로 문제 - 38 정확한 순위
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

// 노드의 개수(N), 간선의 개수(M)
int n, m;
// 2차원 배열(그래프 표현)를 만들기
int graph[501][501];

int main(void) {
    cin >> n >> m;

    // 최단 거리 테이블을 모두 무한으로 초기화
    for (int i = 0; i < 501; i++) {
        fill(graph[i], graph[i] + 501, INF);
    }

    // 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) graph[a][b] = 0;
        }
    }

    // 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
    for (int i = 0; i < m; i++) {
        // A에서 B로 가는 비용은 C라고 설정
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }

    // 점화식에 따라 플로이드 워셜 알고리즘을 수행
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    int result = 0;
    // 각 학생을 번호에 따라 한 명씩 확인하며 도달 가능한지 체크
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] != INF || graph[j][i] != INF) {
                cnt += 1;
            }
        }
        if (cnt == n) {
            result += 1;
        }
    }
    cout << result << '\n';
}

/*
//실패.
int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v[501];
	int ref[501] = { 0, };
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		ref[b] += 1;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ref[i] == 0)
			q.push(i);
	}

	//위상정렬 문제 해결 방식
	vector<int> order;
	while (!q.empty()) {
		int stu_number = q.front();
		q.pop();
		order.push_back(stu_number);

		for (int i = 0; i < v[stu_number].size(); i++) {
			int other = v[stu_number][i];
			ref[other] -= 1;
			if (ref[other] == 0) {
				q.push(other);
			}
		}
	}

}
*/