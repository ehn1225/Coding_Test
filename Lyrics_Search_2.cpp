//이진 탐색 - 30 가사 검색
//프로그래머스 60060
#include <bits/stdc++.h>
using namespace std;
vector<string> word_list[10001];
vector<string> rev_word_list[10001];

int getResutSize(vector<string> list, string start, string end) {
    vector<string>::iterator left = lower_bound(list.begin(), list.end(), start);
    vector<string>::iterator right = upper_bound(list.begin(), list.end(), end);

    return (right - left);
}
string ReplaceString(string word, string from, string to) {
    string result = word;
    int pos = 0;
    while ((pos = result.find(from, pos)) != string::npos) {
        result.replace(pos, from.size(), to);
        pos += to.size();
    }
    return result;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (string it : words) {
        word_list[it.length()].push_back(it);
        reverse(it.begin(), it.end());
        rev_word_list[it.length()].push_back(it);
    }

    for (int i = 0; i < 10001; i++) {
        sort(word_list[i].begin(), word_list[i].end());
        sort(rev_word_list[i].begin(), rev_word_list[i].end());
    }

    for (string query : queries) {
        int result = 0;
        if (query[0] == '?') {
            //접두사 위치에 ?가 있을 경우
            reverse(query.begin(), query.end());
            result = getResutSize(rev_word_list[query.length()], ReplaceString(query, "?", "a"), ReplaceString(query, "?", "z"));
        }
        else {
            //접미사 위치에 ?가 있을 경우
            result = getResutSize(word_list[query.length()], ReplaceString(query, "?", "a"), ReplaceString(query, "?", "z"));
        }
        answer.push_back(result);

    }

    return answer;
}
int main() {
    vector<int> result = solution({ "frodo", "front", "frost","frozen", "frame", "kakao" }, { "fro??", "????o", "fr???","fro???", "pro?" });
    for (int it : result) {
        cout << it << ' ';
    }
    //Result = [3, 2, 4, 1, 0]
}