#include <iostream>
#include <deque>
using namespace std;

int main()
{

	int N, K;
	cin >> N >> K; //N-1이 출구, K개가 0인지 확인해야함

	deque<pair<int, bool>> belt; //cnt,로봇 유무 

	for (int i = 0; i < N*2; i++)
	{
		int tmp;
		cin >> tmp;
		belt.push_back(make_pair(tmp, false)); //0(입구) 1 2(출구) | 3 4 5
		//초기에 로봇 없음
	}
	int cnt = 0;
	while (true)
	{
		int endCnt = K;
		cnt++;
		//이동 
		pair<int, int> last = belt.back();
		belt.pop_back(); //마지막거 제거
		belt.push_front(last); //마지막 위치가 첫번째로 이동함.

		belt[N - 1].second = false;
		//1. 가장 먼저 올라간 로봇부터, 한칸씩 이동함.
		for (int i = N-2; i >= 0; i--) //로봇이 올라갈 수 있는 곳 N까지
		{
			//현재 위치에 로봇이 있으면서, 이동할 위치(i+1)에 로봇이 존재하지 않아야함
			if ((belt[i].second==true)&&(belt[i+1].second == false)&&belt[i+1].first >=1)
			{
				//로봇 이동
				belt[i].second = false; //현재 위치의 로봇을 다음 위치 로봇으로 이동
				belt[i + 1].first -= 1; //내구성 1감소
				belt[i + 1].second = true; 
			}
		}
	
		// 마지막 칸에 있는 애는 항상 내려감.
		//2. 벨트가 각 칸위에 있는 로봇과 함께 이동 
		//내구도가 0이 아니면, 0번째에 로봇이 올라감.
		if(belt.front().first>0)
		{
			belt.front().first -= 1;
			belt.front().second = true; //로봇 올라감
		}
		belt[N - 1].second = false;

		for (int i = 0; i < 2 * N; i++)
		{
			if (belt[i].first <= 0)
				endCnt--;
		}

		if (endCnt <= 0) break;
	}

	cout << cnt << '\n';
}