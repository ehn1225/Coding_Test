#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int w = 0, h = 0; //w : width, h : height
    //b+y = w*h, w >= h
    int total = brown + yellow;
    for (int i = 1; i * i <= total; i++) {
        w++;
        h++;
    }
    while (w * h < total || ((w - 2) * (h - 2) != yellow)) {
        if (((w * h) + (h - 2)) < total)
            w++;
        else
            h--;
    }
    
    answer.push_back(w);
    answer.push_back(h);
    cout << w << " " << h << endl;
    return answer;
}

int main() {
    solution(18,6);

}