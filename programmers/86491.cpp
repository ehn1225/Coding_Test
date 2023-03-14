#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int width_min = 0;
    int height_min = 0;
    
    for(int i = 0; i < sizes_rows; i++){\
        int a = sizes[i][0];
        int b = sizes[i][1];

        //a는 항상 b보다 크거나 같다.
        if (a < b){
            int c = a;
            a = b;
            b = c;
        }
                                        
        if(width_min < a)
            width_min = a;
        if(height_min < b)
            height_min = b;                                        
                                        
    }
    answer = width_min * height_min;
    return answer;
}