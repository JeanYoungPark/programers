#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for (int i = 0; i < size; i++) {
        while (!s.empty() && prices[s.top()] > prices[i]) { //직전에 들어왔던 값이 지금 들어왔던 값보다 크면 -> 가격이 떨어졌다는 의미
            answer[s.top()] = i - s.top(); // 이 값은 항상 1이다.
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }
    return answer;
}


// prices = { 1, 2, 3, 2, 3 };
// 전체 크기에서 index위치 + 1의 값을 빼주는 것이 최대 값임을 이용
//https://programmers.co.kr/learn/courses/30/parts/12081