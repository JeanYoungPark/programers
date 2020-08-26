#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

int main() {

	int t, N, M, num, print, nums[10] = { 0 };
	bool flag = false;
	queue < pair<int, int> > que;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		print = 0; //인쇄한 수
		flag = false; //정답 찾음 유무 확인을 위해 

		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			que.push(make_pair(num,j)); 
			nums[num] += 1;
		}

		for (int j = 9; j >= 0; j--) //중요도 순으로 인쇄를 하니 큰수부터 카운트한다.
		{
			if (nums[j]) { // 해당 중요도가 있다면..
				while (true)
				{
					if (!nums[j]) break; //더이상 찾고 있는 중요도가 없다면 밖으로

					if (que.front().first == j) { //현재 찾는 중요도와 같은 중요도라면..
						print++; //인쇄

						if (que.front().second == M) { //내가 찾는 인쇄물이 맞는지 확인(중복을 피하기 위해)
							flag = true; //맞다면 정답
							break;
						}
						else {
							que.pop(); //아니라면 인괘한후에 삭제
							nums[j]--; //갯수 확인을 위해
						}
					}
					else { //현재 찾는 중요도가 아니라면..
						que.push(que.front());
						que.pop();
					}
				}
				if (flag) break;//정답을 찾았다면 밖으로
			}
		}
		cout << print << '\n';

		memset(nums,0,sizeof(nums));
		while (!que.empty()) que.pop();
	}
}

//https://www.acmicpc.net/problem/1966