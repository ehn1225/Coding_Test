#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
struct DATA {
    int price = 0;;
    int idx = 0;
};

vector<int> solution(vector<int> prices) {
    vector<int> answer = prices;
    stack <DATA> s;


    for (int i = 0; i < prices.size(); i++) {
        DATA tmp = { prices[i], i };

        if (s.empty()) {
            s.push(tmp);
            continue;
        }
        else {
            while (s.top().price > prices[i]) {
                answer[s.top().idx] = i - s.top().idx;
                s.pop();
                if (s.empty())
                    break;
            }
        }
        s.push(tmp);
    }
    while (!s.empty()) {
        answer[s.top().idx] = prices.size() - 1 - s.top().idx;
        s.pop();

    }
    return answer;
}
int main() {
    vector<int> prices = { 1,2,3,2,3 };
    vector<int> result;
    result = solution(prices);
    for (int i = 0; i < 5; i++) {
        cout << result[i];
    }
}