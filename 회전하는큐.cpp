#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, M, num, cnt = 0, index;
	deque <int> deq;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		deq.push_back(i + 1);
	}

	while (M--)
	{
		cin >> num;
		for (int i = 0; i < deq.size(); i++)
		{
			if (deq[i] == num) {
				index = i; //앞으로 갈지 뒤로 갈지 정하기 위해 index를 찾아준다.
				break;
			}
		}

		if (index < deq.size() - index) { //앞으로 가는 것이 뒤로 가는것보다 짧다면..
			while (true)
			{
				if (deq.front() == num) {
					deq.pop_front();
					break;
				}
				cnt++;
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else {
			while (true)
			{
				if (deq.front() == num) {
					deq.pop_front();
					break;
				}
				cnt++;
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}
	}

	cout << cnt;
}

//https://www.acmicpc.net/problem/1021