//DFS/BFS - 19 연산자 끼워 넣기
//백준 14888
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int add, minu, mul, divi;
int min_result = 1e9;
int max_result = -1e9;

void dfs(int depth, int result) {
	if (depth == n) {
		min_result = min(min_result, result);
		max_result = max(max_result, result);
	}
	else {
		if (add > 0) {
			add--;
			dfs(depth + 1, result + v[depth]);
			add++;
		}
		if (minu > 0) {
			minu--;
			dfs(depth + 1, result - v[depth]);
			minu++;
		}
		if (mul > 0) {
			mul--;
			dfs(depth + 1, result * v[depth]);
			mul++;
		}
		if (divi > 0) {
			divi--;
			dfs(depth + 1, result / v[depth]);
			divi++;
		}
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	cin >> add >> minu >> mul >> divi;
	dfs(1, v[0]);

	cout << max_result << '\n';
	cout << min_result << '\n';

}