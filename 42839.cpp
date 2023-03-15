//Programmers 42839 : 완전탐색 - 소수 찾기
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

bool Is_Prime(int a) {
    if (a < 2)
        return false;
    for (int i = 2; i < a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

int size_r = 3;
int pArr[10] = {};
bool check[10] = {};
int *input = NULL;
int input_size = 0;

vector<int> tmp;

void printArray(int* arr) {
    int value = 0;
    for (int i = 0; i < size_r; i++)
        value += (arr[i]*pow(10,size_r-i-1));
    tmp.push_back(value);
}

void permutation(int depth) {
    if (depth == size_r) {
        printArray(pArr);
        return;
    }

    for (int i = 0; i < input_size; i++) {
        if (!check[i]) {
            check[i] = true;
            pArr[depth] = input[i];
            permutation(depth + 1);
            check[i] = false;
        }
    }
}


int solution(string numbers) {
    int answer = 0;
    int item_size = numbers.length();
    input_size = item_size;
    input = new int[item_size];

    for (int i = 0; i < numbers.length(); i++)
        input[i] = numbers[i] - '0';

    for (int i = 1; i <= item_size; i++) {
        size_r = i;
        permutation(0);   
    }

    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < tmp.size(); i++) {
        if (Is_Prime(tmp[i]) == true)
            answer++;
    }


    return answer;
}

int main() {
    cout << solution("011");
}