//Programmers 87946 : 완전탐색 - 피로도
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool checked[8] = {0,};
int max = 0;
void dfs(int depth, int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols){
    for (int i = 0; i < dungeons_rows; i++) {
        if(checked[i] || dungeons[i][0] > k)
            continue;
        checked[i] = true;
        if(max < depth)
            max = depth;
        dfs(depth+1, k-dungeons[i][1], dungeons, dungeons_rows, dungeons_cols);
        checked[i] = false;
    }
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    dfs(1, k, dungeons, dungeons_rows, dungeons_cols);
    return max;
}