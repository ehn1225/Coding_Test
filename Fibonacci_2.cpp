//다이나믹 프로그래밍 - 피보나치 수열
#include <bits/stdc++.h>
using namespace std;

int d[31] = { 0, };
int Fibo_Recursive(int n) {
	//Top-Down
	if (n == 1 || n == 2)
		return 1;
	
	//메모이제이션 기법
	if (d[n] != 0)
		return d[n];

	d[n] = Fibo_Recursive(n - 1) + Fibo_Recursive(n - 2);
	return d[n];
}

int Fibo_Loop(int n) {
	//Bottom-Up
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i < n + 1; i++) {
		d[i] = d[i - 2] + d[i - 1];
	}
	
	return d[n];
}



int main() {
	cout << Fibo_Recursive(30) << '\n';
	cout << Fibo_Loop(30) << '\n';
}