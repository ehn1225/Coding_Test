//perv_permutation함수 학습ㅂ
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v{ 1,2,3,4 };

	do {
		for (auto it : v)
			cout << it << " ";
		cout << endl;
	
	} while (next_permutation(v.begin(), v.end()));


	//5c3
	vector<bool> binary(5);
	fill(binary.end() - 3, binary.end(), true);

	do {
		for (auto it : binary)
			cout << it << " ";
		cout << endl;
	} while (next_permutation(binary.begin(), binary.end()));

}