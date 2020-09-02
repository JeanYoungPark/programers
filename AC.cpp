#include <iostream>
#include <deque>
using namespace std;

int main() {
	int T, n, tmp, err;
	string p, arrT;
	bool fr;
	deque <int> deq;

	cin >> T;

	while (T--)
	{
		fr = 1; //뒤집기 명령이 있을때 앞에서 시작할지 뒤에서 시작할지 결정
		tmp = 0; //10의자리 수 이상을 위해 사용
		err = 0; //에러 체크
		cin >> p >> n >> arrT;
		
		for (int i = 1; i < arrT.length(); i++)
		{
			if (arrT[i] >= '0' && arrT[i] <= '9') { //숫자일때
				tmp *= 10;
				tmp += arrT[i] - '0';
			}
			else {
				if (tmp) deq.push_back(tmp);
				tmp = 0;
			}
		}

		for (int i = 0; i < p.length(); i++)
		{
			if (p[i] == 'R') fr = !fr; //뒤집기일 경우 앞에서 시작 또는 뒤에서 시작을 결정
			else {
				if (deq.empty()) { //값이 없을때 삭제하면 에러
					err = 1;
					break;
				}
				else {
					if (fr) deq.pop_front(); //앞에서 시작일때는 앞에서 삭제
					else deq.pop_back();
				}
			}
		}
		
		if (err) {
			cout << "error" << '\n';
		}
		else {
			cout << "[";
			while (!deq.empty())
			{
				if (fr) {
					cout << deq.front();
					deq.pop_front();
				}
				else {
					cout << deq.back();
					deq.pop_back();
				}

				if (!deq.empty()) cout << ",";
			}
			cout << "]" << '\n';
		}
	}
}

//https://www.acmicpc.net/problem/5430