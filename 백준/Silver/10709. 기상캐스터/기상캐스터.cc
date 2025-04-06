#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int H,W;
	cin>>H>>W;

	const int Max = 987654321;

	vector<vector<int>> city(H, vector<int>(W, Max));

	for (int i = 0; i < H; i++)
	{
		string cloud;

		cin>>cloud;

		for (int j = 0; j < cloud.size(); j++)
		{
			if (cloud[j] == 'c')
			{
				//구름 있는 위치 초기화
				city[i][j] = 0;
			}
		}
	}

	//동쪽으로 한 칸씩 이동 => 너비만큼 이동해야한다.
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			for (int k = 1; k < W; k++)
			{	
				//최소 값으로 변환 해주어야지 처음 몇 초 뒤에 구름이 오는지 알 수 있음.
				city[j][k] = min(city[j][k], city[j][k-1] + 1);
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (city[i][j] == Max)
			{
				cout<<-1<<' ';
			}
			else
			{
				cout << city[i][j] << ' ';
			}
		}
		cout<<'\n';
	}
	return 0;
}

/*
* 동쪽으로 이동 -> +1씩 증가
* 초기값 INF로 맞추고, 'c'일 때 0으로 리셋
* min 값을 비교해서 더 작은 값으로 리셋
* 한바퀴 돌지 않음. 
*/