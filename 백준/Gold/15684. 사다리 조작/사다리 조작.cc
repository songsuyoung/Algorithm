#include <bits/stdc++.h>
using namespace std;

bool Move(int H, int N, vector<vector<bool>> &ladder)
{
	
	//자기 자신한테 갈 수 있는지를 확인한다.
	for (int i = 1; i <= N; i++)
	{
		int start = i;
		for (int j = 1; j <= H; j++)
		{
			if (ladder[j][start])
			{
				//투르면 옆으로 이동
				start+=1;
			}
			else if (ladder[j][start - 1])
			{
				//왼쪽으로 이동
				start-=1;
			}
		}

		if (start != i)
		{
			//도착했는데 자기 자신이 아님
			return false;
		}
	}

	return true;
}
int answer = 4;
//사다리를 놓는 과정 
void recursive(int N, int H, vector<vector<bool>> &ladder, int h, int selected)
{
	if (selected > 3 || selected>=answer)
	{
		//실패
		return;
	}

	bool bMove = Move(H, N, ladder);

	if (bMove)
	{
		answer = min(answer, selected);
		return;
	}

	for (int i = h; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			//안겹칠 때 자기 자신한테 갈 수 있는지를 체크해야한다.
			//이전에 그엇으면 방문 안한다.
			if (ladder[i][j] || ladder[i][j + 1] || ladder[i][j - 1]) continue;
			ladder[i][j] = true;
			recursive(N,H, ladder, i, selected+1);
			ladder[i][j] = false;
		}
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N,M,H;
	cin>>N>>M>>H;

	//변형하지 말고 해라
	vector<vector<bool>> ladder(H+1,vector<bool>(N+1));

	for (int i = 0; i < M; i++)
	{
		int level, line;
		cin>>level>>line;

		ladder[level][line]= 1; //줄 그음
	}

	recursive(N,H, ladder, 1, 0);

	if (answer == 4)
	{
		answer = -1;
	}
	cout<<answer<<'\n';
}

/*
사다리 게임 N개 세로선, M개 가로선

인접한 세로 선사이에는 가로선을 놓을 수 있다. => 즉 +1, -1 에는 가로선을 놓을 수 있다.
두 가로선이 연속하거나 서로 접하면 안된다. => 같은 level에 +1 +1 지나가면 안된다는 소리 (또는 -1, -1 지나가면 안된다)

1. 가로 선을 추가한다. 
2. 완료되었을 때 i번 세로선의 결과가 i번이 나오는 지를 확인한다.
3. 만약 나온다면, 현재 놓은 가로선 개수 최솟값을 저장한다.


1-2 2-3 3-4 4-5

[1][2]
[2][3]
[3][4]
[4][5]

반대 방향도 가능

[2][1]
[3][2]
[4][3]
[5][4]


[1][2] [2][3] => 체크되어지면 안된다.

가로선을 판단하기 위한 level 존재
[level][1][2] == [level][2][3] 틀림!

고민 되는 부분 : 가로 선을 추가하기 전에 그엇는지를 확인할지 or 선을 다 추가하고 나서, 중복되었는지.. 
H = 30

1. 갈수 있는 경로를 미리 만든다.
1-2
2-1
=> vector<pair<int,int>> 연결

1-2 4-5

긋는다.
안긋는다.

*/