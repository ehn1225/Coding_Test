#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(pair<string, int>&a, pair<string, int> &b) {
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<int>> m;
    map<string, int> m_info;

    int music_count = genres.size();
    for (int i = 0; i < music_count; i++) { //장르별 음악의 index를 보관.
        auto it = m.find(genres[i]);
        if (it == m.end()) {
            m[genres[i]] = vector <int>{ i };
        }
        else {
            m[genres[i]].push_back(i); 
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) { //장르 내 재생횟수 순 정렬
        vector<int> tmp = it->second;
        it->second.clear();
        int size = tmp.size();
        for (int i = 0; i < size; i++) {
            int max_index = tmp[0];
            for (auto it2 = tmp.begin(); it2 != tmp.end(); it2++) {
                if (plays[max_index] < plays[*it2]) {
                    max_index = *it2;
                }
            }
            it->second.push_back(max_index);
            tmp.erase(remove(tmp.begin(), tmp.end(), max_index), tmp.end());
        }

    }

    for (auto it = m.begin(); it != m.end(); it++) { //장르별 총 재생횟수를 m_info에 저장함.
        int sum = 0;
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            sum += plays[*it2];
        }
        m_info[it->first] = sum;
    }

    vector<pair<string, int>> vec(m_info.begin(), m_info.end()); //장르를 총 재생횟수별로 정렬함.
    sort(vec.begin(), vec.end(), cmp);


    for (auto it = vec.begin(); it != vec.end(); it++) { //총 재생횟수가 많은 장르 순서로 answer 백터에 담음.
        for (int i = 0; i < m[it->first].size() && i < 2; i++) {
            answer.push_back(m[it->first][i]);
        }
    }

    return answer;
}

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    vector<int> result;
    result = solution(genres, plays);
}
