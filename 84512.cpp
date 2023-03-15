//Programmers 84512 : 완전탐색 - 모음사전
#include <bits/stdc++.h>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    vector<string> v;
	char arr[6] = {'\0', 'A', 'E', 'I', 'O', 'U'};
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				for (int l = 0; l < 6; l++) {
					for (int m = 0; m < 6; m++) {
						char temp[6] = { 0, };
						temp[0] = arr[i];
						temp[1] = arr[j];
						temp[2] = arr[k];
						temp[3] = arr[l];
						temp[4] = arr[m];
						string tmp(temp);
						v.push_back(tmp);
					}
				}
			}
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	auto it = find(v.begin(), v.end(), word);
	if (it != v.end()) {
		answer = it - v.begin() + 1;
	}
    
    return answer;
}