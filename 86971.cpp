//Programmers 86971 : 완전탐색 - 전력망을 둘로 나누기
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[101][101] = {0, };
bool check[101] = {0,};
int result = 0;
int count_conn(int node, int size){
    check[node] = true;
    result++;
    for(int i =1; i <= size; i++){
        if(arr[node][i] == 1 && check[i] == false)
            count_conn(i, size);
    }
    check[node] = false;
    return result;
}

int solution(int n, vector<vector<int>> wires) {
    //연결 관계를 행렬 형태로 저장
    for (int i= 0; i < n-1; i++){
        int x = wires[i][0];
        int y = wires[i][1];
        arr[x][y] = 1;
        arr[y][x] = 1;

        //각 노드별 연결 수
        arr[x][0]++;
        arr[y][0]++;
    }
    int answer = n;
    //각 노드의 연결 수만큼 순회
    for (int i= 1; i <= n; i++){
        //leaf 노드가 아니라면
        if (arr[i][0] != 1){
            for(int j = 1; j <= n; j++){
                //특정 노드와 연결되어 있다면
                if(arr[i][j] == 1){
                    //i ,j의 연결을 끊고, 카운트 후 다시 복구
                    arr[i][j] = 0;
                    arr[j][i] = 0;

                    result = 0;
                    int a = count_conn(i, n);
                    result = 0;
                    int b = count_conn(j, n);
                    int diff = (a > b) ? a - b : b - a;
                    if(answer > diff)
                        answer = diff;
                    
                    arr[i][j] = 1;
                    arr[j][i] = 1;
                    
                }
            }
        }
    }
    
    return answer;
}