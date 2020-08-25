#include <unordered_map> // 정렬되지 않은 map
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string, int> wear;
    for (int i = 0; i < clothes.size(); i++) {
        wear[clothes[i][1]]++;
    } //의상종류에 대해 각각 갯수를 확인

    //auto는 타입추론 측 초기화 값에 따라 알아서 데이터 타입을 정해준다.
    for (auto i = wear.begin(); i != wear.end(); i++) {
        answer *= i->second + 1;
    }
    return answer - 1; //아무것도 입지 않은 상황은 제외
}

//clothes : 
//[
//    [yellow_hat, headgear],
//    [blue_sunglasses, eyewear],
//    [green_turban, headgear]
//]