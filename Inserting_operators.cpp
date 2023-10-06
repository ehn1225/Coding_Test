//DFS/BFS문제 - 19 연산자 끼워 넣기
#include <bits/stdc++.h>
using namespace std;

int sum_min = 1e9, sum_max = -1e9;
int n, add, sub, mul, divi;
vector<int> arr;

void dfs(int depth, int now) {
	if (depth == n) {
		sum_min = min(sum_min, now);
		sum_max = max(sum_max, now);
	}
	else {
		if (add > 0) {
			add--;
			dfs(depth + 1, now + arr[depth]);
			add++;
		}
		if (sub > 0) {
			sub--;
			dfs(depth + 1, now - arr[depth]);
			sub++;
		}
		if (mul > 0) {
			mul--;
			dfs(depth + 1, now * arr[depth]);
			mul++;
		}
		if (divi > 0) {
			divi--;
			dfs(depth + 1, now / arr[depth]);
			divi++;
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	cin >> add >> sub >> mul >> divi;

	dfs(1, arr[0]);

	cout << sum_max << endl;
	cout << sum_min << endl;
}

/*
int main() {
	int sum_min = 1e9, sum_max = -1e9;
	int arr[101] = {0,};
	int n, plus, minus, mul, divi;

	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	cin >> plus >> minus >> mul >> divi;

	vector<char> operations;
	for (int i = 0; i < plus; i++)
		operations.push_back('+');	
	for (int i = 0; i < minus; i++)
		operations.push_back('-');	
	for (int i = 0; i < mul; i++)
		operations.push_back('*');	
	for (int i = 0; i < divi; i++)
		operations.push_back('/');

	do {
		int result = arr[0];
		int pos = 0;
		for (int i = 1; i < n; i++){
			if (operations[pos] == '+')
				result += arr[i];
			if (operations[pos] == '-')
				result -= arr[i];
			if (operations[pos] == '*')
				result *= arr[i];
			if (operations[pos] == '/')
				result /= arr[i];
			pos++;
		}

		sum_min = min(sum_min, result);
		sum_max = max(sum_max, result);

	} while (next_permutation(operations.begin(), operations.end()));

	cout << sum_max << endl;
	cout << sum_min << endl;

}

*/