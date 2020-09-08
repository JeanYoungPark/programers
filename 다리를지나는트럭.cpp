#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue <pair<int, int>> que; //트럭무게, 현재지나가고 있는 위치
    int answer = 0, total = 0, i = 0, cnt = 0;

    while (!que.empty() || i < truck_weights.size()) { //지나가고 있는 트럭 또는 대기중인 트럭이 있다면

        if (que.front().second == bridge_length) { //현재 지나가고 있는 위치가 다리의 위치와 같다면 (다리를 지난상태)
            total -= que.front().first; //다리의 올라가 있는 트럭들의 무게에서 제외
            que.pop();
        }

        if (i < truck_weights.size()) { //대기중인 트럭이 있다면
            if (total + truck_weights[i] <= weight) { //다리를 건너게 될 트럭 + 다리를 건너는 트럭의 무게의 합이 다리의 무게보다 작거나 같다면
                total += truck_weights[i];
                que.push({ truck_weights[i],0 }); //다리를 건너고 있는 리스트에 추가
                i++;
            }
        }

        cnt = que.size(); //각각 트럭의 다리 지나는 위치를 증가 시키기 위함
        while (cnt--) {
            que.push({ que.front().first,(que.front().second) + 1 });
            que.pop();
        }
        answer++; //시간초++
    }

    return answer;
}

int main() {
    int bridge_length = 2, int weight = 10, vector<int> truck_weights = {7,4,5,6};
    solution(bridge_length, weight, truck_weights);
}

//https://programmers.co.kr/learn/courses/30/parts/12081