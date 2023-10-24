//구현 문제 - 14 외벽 점검
//프로그래머스 60062
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    // 길이를 2배로 늘려서 '원형'을 일자 형태로 변경
    int length = weak.size();
    for (int i = 0; i < length; i++) {
        weak.push_back(weak[i] + n);
    }
    // 투입할 친구 수의 최솟값을 찾아야 하므로 len(dist) + 1로 초기화
    int answer = dist.size() + 1;
    //weak 배열의 첫번째 부터 확인
    for (int start = 0; start < length; start++) {
        do {
            int cnt = 1;
            int position = weak[start] + dist[cnt - 1];

            //시작점부터 모든 취약한 지점을 확인
            for (int index = start; index < start + length; index++) {
                // 점검할 수 있는 위치를 벗어나는 경우
                if (position < weak[index]) {
                    cnt += 1;
                    if (cnt > dist.size()) {
                        break;
                    }
                    position = weak[index] + dist[cnt - 1];
                }
            }
            answer = min(answer, cnt);
        } while (next_permutation(dist.begin(), dist.end())); // 친구를 나열하는 모든 경우 각각에 대하여 확인
    }
    if (answer > dist.size()) {
        return -1;
    }
    return answer;
}

int main() {
	cout << solution(12, { 1, 5, 6, 10 }, { 1, 2, 3, 4 });	//2
	cout << solution(12, { 1, 3, 4, 9, 10}, {3, 5, 7});		//1

}