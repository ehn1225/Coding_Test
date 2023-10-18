//기타 알고리즘 - 예제 B-2 암호 만들기
//백준 1759
#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool Check(string tmp) {
    int size = tmp.length();
    int vowels = 0;
    for (int i = 0; i < size; i++) {
        if (tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u')
            vowels++;
    }

    if (vowels > 0 && size - vowels > 1)
        return true;
    else
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, c;
    cin >> l >> c;

    vector<char> v;
    for (int i = 0; i < c; i++) {
        char chr;
        cin >> chr;
        v.push_back(chr);
    }
    sort(v.begin(), v.end());

    vector<bool> combination(c);
    fill(combination.end() - l, combination.end(), true);
    vector<string> result;

    do {
        string tmp;
        for (int i = 0; i < c; i++) {
            if (combination[i] == 1)
                tmp += v[i];
        }
        if(Check(tmp))
            result.push_back(tmp);
    
    } while (next_permutation(combination.begin(), combination.end()));

    sort(result.begin(), result.end());

    for (string it : result)
        cout << it << '\n';

}