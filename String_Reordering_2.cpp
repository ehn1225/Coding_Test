//구현 문제 - 8 문자열 재정렬
#include <bits/stdc++.h>
using namespace std;

int main() {
	string input;
	cin >> input;

	vector<char> v;
	int sum = 0;

	for (int i = 0; i < input.length(); i++) {
		char c = input[i];
		if (c < 'A')
			sum += (c - '0');
		else
			v.push_back(c);
	}

	sort(v.begin(), v.end());

	for (char it : v) {
		cout << it;
	}
	cout << sum << endl;


	/*
	int arr[26] = { 0, };
	for (int i = 0; i < input.length(); i++) {
		char c = input[i];
		if (c < 'A')
			sum += (c - '0');
		else
			arr[c - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << (char)('A' + i);
		}
	}

	cout << sum << '\n';
	*/

}