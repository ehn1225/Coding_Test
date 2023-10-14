//이진 탐색 - 30 가사 검색
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

using namespace std;

// 값이 [left_value, right_value]인 데이터의 개수를 반환하는 함수
int countByRange(vector<string>& v, string leftValue, string rightValue) {
    vector<string>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<string>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

// 문자열 내에서 특정한 문자열을 다른 문자열로 모두 치환하는 함수
string replaceAll(string str, string from, string to) {
    string res = str;
    int pos = 0;
    while ((pos = res.find(from, pos)) != string::npos)
    {
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}

// 모든 단어들을 길이마다 나누어서 저장하기 위한 리스트
vector<string> arr[10001];
// 모든 단어들을 길이마다 나누어서 뒤집어 저장하기 위한 리스트
vector<string> reversed_arr[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // 모든 단어를 접미사 와일드카드 배열, 접두사 와일드카드 배열에 각각 삽입
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        arr[word.size()].push_back(word); // 단어를 삽입
        reverse(word.begin(), word.end());
        reversed_arr[word.size()].push_back(word); // 단어를 뒤집어서 삽입
    }

    // 이진 탐색을 수행하기 위해 각 단어 리스트 정렬 수행
    for (int i = 0; i < 10001; i++) {
        sort(arr[i].begin(), arr[i].end());
        sort(reversed_arr[i].begin(), reversed_arr[i].end());
    }

    // 쿼리를 하나씩 확인하며 처리
    for (int i = 0; i < queries.size(); i++) {
        string q = queries[i];
        int res = 0;
        if (q[0] != '?') { // 접미사에 와일드 카드가 붙은 경우
            res = countByRange(arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }
        else { // 접두사에 와일드 카드가 붙은 경우
            reverse(q.begin(), q.end());
            res = countByRange(reversed_arr[q.size()], replaceAll(q, "?", "a"), replaceAll(q, "?", "z"));
        }
        // 검색된 단어의 개수를 저장
        answer.push_back(res);
    }
    return answer;
}

/*
//실패. binarySearch_min 함수 문제 발생
bool compare(string a, string b) {
    if (a.length() < b.length())
        return true;
    else if (a.length() > b.length())
        return false;

    return a < b;
}

int binarySearch_min(vector<string> words, int pos, char c, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;

    if ((mid == 0 || c > words[mid - 1][pos]) && words[mid][pos] == c)
        return mid;
    else if (words[mid][pos] >= c)
        return binarySearch_min(words, pos, c, left, mid - 1);
    else
        return binarySearch_min(words, pos, c, mid + 1, right);

}
int binarySearch_max(vector<string> words, int pos, char c, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;

    if ((mid == words.size() - 1 || c < words[mid + 1][pos]) && words[mid][pos] == c)
        return mid;
    else if (words[mid][pos] > c)
        return binarySearch_max(words, pos, c, left, mid - 1);
    else
        return binarySearch_max(words, pos, c, mid + 1, right);

}

int binarySearch_word_left(vector<string> words, int length, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;

    if ((mid == 0 || length > words[mid - 1].length()) && words[mid].length() == length)
        return mid;
    else if (words[mid].length() >= length)
        return binarySearch_word_left(words, length, left, mid - 1);
    else
        return binarySearch_word_left(words, length, mid + 1, right);
}
int binarySearch_word_right(vector<string> words, int length, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;

    if ((mid == words.size() - 1 || length < words[mid + 1].length()) && words[mid].length() == length)
        return mid;
    else if (words[mid].length() > length)
        return binarySearch_word_right(words, length, left, mid - 1);
    else
        return binarySearch_word_right(words, length, mid + 1, right);
}

int getSearchResult(vector<string> words, string query) {
    int query_len = query.size();
    int left = binarySearch_word_left(words, query_len, 0, words.size());
    if (left == -1)
        return 0;
    int right = binarySearch_word_right(words, query_len, 0, words.size());
    int answer = 0;

    for (int pos = 0; pos < query_len; pos++) {
        char c = query[pos];
        if (c == '?') continue;
        left = binarySearch_min(words, pos, c, left, right);
        if (left == -1) break;
        right = binarySearch_max(words, pos, c, left, right);
    }

    if (left == -1)
        return 0;
    else
        return (right - left + 1);

}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    sort(words.begin(), words.end(), compare); //글자순, 사전 순

    for (int i = 0; i < queries.size(); i++) {
        int result = getSearchResult(words, queries[i]);
        answer.push_back(result);
    }

    return answer;
}

int main() {
    vector<string> v = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> q = { "fro??", "????o", "fr???", "fro???", "pro?" };

    sort(v.begin(), v.end(), compare);
    vector<int> ans = solution(v, q);

    for (auto it : ans)
        cout << it << endl;

}

*/