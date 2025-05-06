#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> isVisited(11,vector<bool>(11,false));

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};
int answer = INT_MAX;
void recursive(int N, vector<vector<int>>& board, int flower, int R, int C)
{
	if (flower <= 0)
	{
		int sum = 0;
		//세개 모두 놓았음.
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (isVisited[i][j])
				{
					sum+=board[i][j];
				}
			}
		}

		answer =min(answer, sum);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{	
			//심을 수 있다.
			bool bSuccess = true;
			for (int k = 0; k < 4; k++)
			{
				int nextR = i + rows[k];
				int nextC = j + cols[k];

				if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N || isVisited[nextR][nextC])
				{
					bSuccess = false;
					break;
				}
			}

			//심을 수 있다면.
			if (bSuccess)
			{
				int sum  = board[i][j];

				isVisited[i][j] = true;
				for (int k = 0; k < 4; k++)
				{
					int nextR = i + rows[k];
					int nextC = j + cols[k];

					sum += board[nextR][nextC];
					isVisited[nextR][nextC] = true;
				}
				
				recursive(N, board,flower-1, i, j);

				isVisited[i][j] = false;
				for (int k = 0; k < 4; k++)
				{
					int nextR = i + rows[k];
					int nextC = j + cols[k];

					isVisited[nextR][nextC] = false;
				}
			}
		}
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	vector<vector<int>> board(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>board[i][j];
		}
	}

	//0,0 시작
	recursive(N, board, 3, 0, 0); //꽃잎 3개
	cout<<answer<<'\n';
}
/*
식목일을 맞이한 진이는 꽃길을 걷고 싶었음.
꽃을 심으면 1년후 꽃이 핀다.

씨앗이 3개 밖에 없음.

N*N격자 모양이고 

씨앗을 1,1 ~ N,N 지점 중하나 심을 수 있고
꽃이 피면 상하좌우 모양

조건
1. 다른 꽃입에 닿으면 두 꽃 모두 죽는다. (겹침 없어야함)
2. 경계에 둘 수 없다.
3. 가장 싼 가격에 화단을 대여하고 싶다 => 최솟값



1. 완전 탐색 => 꽃 선택 상하좌우 체크 (다음 꽃이 선택하지 않도록)
2. 경계 X
3. 모두 더해서 최솟값 선택 => 완전 탐색 (백트래킹)

*/