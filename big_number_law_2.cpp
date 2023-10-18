//그리디 - 2 큰 수의 법칙
#include <bits/stdc++.h>
using namespace std;


int main() {

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	/*
	//1안 : 한 사이클의 합을 구하고, 사이클 수 만큼 곱함. 마지막에 나머지의 개수만큼 최대값 곱해서 더함.
	int group = (v[v.size() - 1] * k) + v[v.size() - 2];
	int loop = m / (k + 1);
	int answer = (group * loop) + (v[v.size() - 1] * (m % (k + 1)));
	*/

	//2안 : 가장 큰 수가 더해지는 횟수를 구한 다음, 이를 이용해 두 번째로 큰 수가 더해지는 횟수를 구함.

	//m / (k + 1) : 제일 큰 수 k개와, 두번째로 큰 수 1개 => 하나의 세트이므로, 몇개의 세트가 들어가는지 몫을 구함.
	//(m / (k + 1)) * k : 제일 큰 수는 한 세트에 k개씩 들어가므로, 전체 세트에 제일 큰 수는 (세트의 갯수 * k개) 가 들어감
	//(m % (k + 1)) : 세트로 나눠지지 않는 나머지의 개수. 나머지는 모두 제일 큰 수가 된다.
	int answer = 0;
	int count = (m / (k + 1)) * k + (m % (k + 1));//제일 큰 수의 개수
	
	answer = count * v[v.size() - 1];	//제일 큰 수와 그의 개수만큼 곱해서 결과에 대입
	answer += (m - count) * v[v.size() - 2];	//두번째로 큰 수와 그의 개수만큼 곱해서 결과에 대입

	cout << answer << '\n';
}

/*
int main() {

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int group = (v[v.size() - 1] * k) + v[v.size() - 2];
	int loop = m / (k + 1);
	int answer = (group * loop) + (v[v.size() - 1] * (m % (k + 1)));
	
	cout << answer << '\n';
}
*/