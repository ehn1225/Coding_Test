//Programmers 42586 : 스택/큐 - 기능개발
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct WORK {
    int progress = 0;
    int speed = 0;
    int remaining_time = 0;
};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <WORK> q;

    for (int i = 0; i < progresses.size(); i++) {//task 등록.
        WORK tesk;
        tesk.progress = progresses[i];
        tesk.speed = speeds[i];
        tesk.remaining_time = ((100 - tesk.progress) / tesk.speed);
        if ((100 - tesk.progress) % tesk.speed != 0)//잔여일이 나머지가 생길 경우 1일 추가.
            tesk.remaining_time += 1;
        q.push(tesk);
    }

    int idx = 0;
    int sum = 0;
    while (!q.empty()) {
        WORK tmp = q.front();
        
        if(tmp.remaining_time <= idx){
            sum++;
            q.pop();
            continue;
        }
        if (sum != 0) {
            answer.push_back(sum);
        }
        idx++;
        sum = 0;
    }
    if (sum != 0) {
        answer.push_back(sum);
    }


    return answer;
}

int main() {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1,30,5};
    vector <int> result;
    result = solution(progresses, speeds);
 
}