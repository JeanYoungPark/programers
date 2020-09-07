#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day) //정답이 비어있거나 뒤의 날짜가 앞의 최대 날짜보다 큰 경우
            answer.push_back(1);
        else
            ++answer.back(); //제일 뒤의 값에 수를 더해준다.

        if (max_day < day) //앞의 최대 날짜보다 더 큰 최대 날짜가 나온경우 초기화
            max_day = day;
    }

    return answer;
}

int main() {
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };
    solution(progresses, speeds);
}

//https://programmers.co.kr/learn/courses/30/parts/12081