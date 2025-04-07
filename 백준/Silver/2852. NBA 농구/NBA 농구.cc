#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int N;
	cin>>N;

	
	vector<int> team(2,0);
	vector<int> win(2,48*60);
	vector<int> total(2, 0); //누적용

	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		string time;

		cin>>idx>>time;

		idx = idx-1; //0-1로 보간
		team[idx]++;

		int pos = time.find(':');

		int mm = stoi(time.substr(0, pos));
		int ss = stoi(time.substr(pos+1));

		int tt = mm * 60 + ss;

		//이김
		int other = (idx + 1) % 2;

		if (team[idx] > team[other])
		{
			win[idx] = min(win[idx], tt); //이길 때에는 가장 작은 값을 유지
		}
		else if(team[idx] == team[other])
		{
			//비긴 케이스 비켰을 때 출력
			total[other] += abs(tt - win[other]);
			win[other] = 48*60;
		}
	}

	//마지막 48분 일때, 계산을 위해 마지막 idx 누군지 확인
	for (int i = 0; i < 2; i++)
	{
		total[i] += abs(win[i] - 48 * 60); //끝났을 때 누적 값 업데이트
	}

	for (int i = 0; i < 2; i++)
	{
		string min = to_string(total[i] / 60);

		//cout<<total[i]<<' ';
		if (min.size() == 1)
		{
			min = "0" + min;
		}
		string sec = to_string(total[i] % 60);

		if (sec.size() == 1)
		{
			sec = "0" + sec;
		}

		cout << min << ":" << sec << '\n';
	}
	
}

/*
1
1 20:00

A 20:00 => time 20*60+00 => 1200

------------

1 01:00 => 01*60 + 00 => 60 (1:0 => 시간 저장)
2 21:00 => 21*60 + 00 => 1260 - 60 => 1200 => 20:00 출력! (1:0 => 1:1 같아지는 시점에 출력)
2 31:00 => 31*60 + 00 => 1860 (1:2 => 시간 저장)

48:00 => 48*60 + 00 => 2880 - 1860 (끝났을 때 48*60 - 저장한 시간을 빼서 출력)
*/