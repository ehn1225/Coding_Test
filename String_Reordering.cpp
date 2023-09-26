//구현문제 - 8 문자열 재정렬
#include <bits/stdc++.h>
using namespace std;

string str;
vector<char> result;
int value = 0;

int main(void) {
    cin >> str;

    // 문자를 하나씩 확인하며
    for (int i = 0; i < str.size(); i++) {
        // 알파벳인 경우 결과 리스트에 삽입
        if (isalpha(str[i])) {
            result.push_back(str[i]);
        }
        // 숫자는 따로 더하기
        else {
            value += str[i] - '0';
        }
    }

    // 알파벳을 오름차순으로 정렬
    sort(result.begin(), result.end());

    // 알파벳을 차례대로 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }

    // 숫자가 하나라도 존재하는 경우 가장 뒤에 출력
    if (value != 0) cout << value;
    cout << '\n';
}

/*
int main() {
	int arr[26] = { 0, };
	
	string s_input;
	cin >> s_input;

	int sum = 0;
	for (int i = 0; i < s_input.size(); i++) {
		char c = s_input[i];
		if (c - 'A' < 0) {
			//숫자
			sum += (c - '0');
		}
		else {
			//대문자
			arr[c - 'A']++;
		}

	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < arr[i]; j++)
			cout << (char)('A' + i);
	}
	cout << sum << endl;

}
*/