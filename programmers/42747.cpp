#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    sort(citations.begin(), citations.end());
    
    /*
        i는 h-index.
        pos는 배열 탐색을 위한 용도
        count는 h-index가 배열에서 몇번째 위치인지 파악하는 용도
        left는 i보다 크거나 같은 논문의 수
    
    */
    for (int i = 0; i < citations[size-1]; i++) {
        int pos = 0;
        int count = 0;
        while(pos < size && citations[pos] < i){
            count++;
            pos++;        
        }
        int left = size - count;
        if (left >= i)
            answer = i;

    }
    return answer;
}

int main() {
   vector<int> a = {3,4,5,11,15,16,17,18,19,20}; //7
   //vector<int> a = { 3,0,6,1,5 }; //7

    cout << solution(a);
    
}