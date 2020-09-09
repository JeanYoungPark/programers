#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> printer;                         //queue에 index 삽입.
    vector<int> sorted;                         //정렬된 결과 저장용
    for (int i = 0; i < priorities.size(); i++) {
        printer.push(i);
    }
    while (!printer.empty()) {
        int now_index = printer.front();
        printer.pop();
        //max_element = 최대값 원소를 찾는다.
        if (priorities[now_index] != *max_element(priorities.begin(), priorities.end())) { 
            //최대값이 아닌경우
            printer.push(now_index);
        }
        else {
            //최대값이 맞는경우
            sorted.push_back(now_index); //프린트될 순서대로 index값을 넣어준다.
            priorities[now_index] = 0; //최대값을 없애기 위해 0 을 대입
        }
    }
    for (int i = 0; i < sorted.size(); i++) {
        if (sorted[i] == location) return i + 1;
    }
}

int main() {
    vector<int> priorities = { 1,1,9,1,1,1 };
    int location = 0;
    solution(priorities, location);
}

//https://programmers.co.kr/learn/courses/30/parts/12081