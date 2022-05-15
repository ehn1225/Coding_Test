#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
#define SIZE_OF_ARR 1000000
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 1;
    int arr[SIZE_OF_ARR];
    int pos = 0;
    memset(arr, 0, SIZE_OF_ARR *sizeof(int));

    while (pos < truck_weights.size()) {
        int now = truck_weights[pos];
        if (arr[time] + now <= weight) {
            for (int j = 0; j < bridge_length; j++) {
                arr[time + j] = arr[time + j]+ now;
            }
            pos++;
        }
        time++;
    }
    
    for (int i = 1; i < SIZE_OF_ARR; i++) {
        if (arr[i] == 0) {
            answer = i;
            break;
        }
    }

    return answer;
}

int main() {
    vector<int>a = {10};
    cout << solution(100, 100, a);

}