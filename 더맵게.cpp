#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, first = 0;
    priority_queue<int, vector<int>, greater<int>> que; //우선순위 큐를 사용
    for (int i = 0; i < scoville.size(); i++) {
        que.push(scoville[i]);
    }

    while (que.top() < K) { //답이 나올때 까지 반복(K보다 크거나 같은 값이 나올때까지)
        if (que.size() == 1) return answer = -1; //남은 원소가 한개일 경우 계산을 할 수 없음으로 중단
        answer++;
        first = que.top();
        que.pop();
        que.push(first + (que.top() * 2)); //제일작은 수와 두번째로 작은 수로 계산한 값을 푸시
        que.pop();
    }

    return answer;
}

int main() {
    vector<int> scoville = { 1,2,3,9,10,12 };
    int k = 7;
    solution(scoville, k);
}

//https://programmers.co.kr/learn/courses/30/lessons/42626