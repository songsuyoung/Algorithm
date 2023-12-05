#include <iostream>
#include <vector>
using namespace std;

void print(int R, int C, vector<int> arr[][51])
{
	cout << '\n';
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << arr[i][j][0] << ' ';
		}
		cout << '\n';
	}
}

void UpCycle(int R,int C, pair<int, int>& pos,vector<int> arr[][51])
{

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	for (int r = pos.first - 1; r > 0; r--)
	{
		//아래로 이동
		arr[r][pos.second][0] = arr[r-1][pos.second][0];
	}

	//왼쪽부터 진행
	for (int c = 0; c < C - 1; c++)
	{
		arr[0][c][0] = arr[0][c + 1][0];
	}

	//위쪽 진행
	for (int r = 0; r < pos.first; r++)
	{
		arr[r][C - 1][0] = arr[r + 1][C - 1][0];
	}

	//오른쪽진행
	for (int c = C - 1; c > 0; c--)
	{
		arr[pos.first][c][0] = arr[pos.first][c - 1][0];
	}
	//공기청정기에서 부는 바람은 미세먼지가 없는 바람임
	arr[pos.first][1][0] = 0;
}

void DownCycle(int R, int C, pair<int, int> &pos, vector<int> arr[][51])
{
	for (int r = pos.first + 1; r < R-1; r++)
	{
		//위로 이동
		arr[r][pos.second][0] = arr[r+1][pos.second][0];
	}

	//왼쪽부터 진행
	for (int c = 0; c < C - 1; c++)
	{
		arr[R-1][c][0] = arr[R-1][c + 1][0];
	}

	//아래쪽 진행
	for (int r = R-1; r > pos.first; r--)
	{
		arr[r][C - 1][0] = arr[r - 1][C - 1][0];
	}

	//오른쪽진행
	for (int c = C - 1; c > 0; c--)
	{
		arr[pos.first][c][0] = arr[pos.first][c - 1][0];
	}
	//공기청정기에서 부는 바람은 미세먼지가 없는 바람임
	arr[pos.first][1][0] = 0;
}

int main()
{
	int R, C, T;

	cin >> R >> C >> T;
	vector<int> arr[51][51] = {};
	
	vector<pair<int, int>> pos = {};

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int val;
			cin >> val;

			arr[i][j].push_back(val);
			
			if(val==-1)
			{
				pos.push_back(make_pair(i, j)); //상부 하부에 대해 row/col저장
			}
		}
	}

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	while (T > 0)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				int amount = arr[i][j][0] / 5;
				int cnt = 0;
				//r,c에 있는 미세먼지는 인접한 네방향으로 확산
				for (int k = 0; k < 4; k++)
				{
					int nextR = i + rows[k];
					int nextC = j + cols[k];
					//인접한 방향에 공기청정기가 있거나 칸이없으면 확산 노노
					if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C || arr[nextR][nextC][0] == -1) continue;
					cnt++;
					arr[nextR][nextC].push_back(amount);
				}
				arr[i][j][0] -= (amount * cnt);
				//A(r,c)/5
				//A(r,c)=A(r,c)-(A(r,c)/5*N)
			}
		}
		//print(R, C, arr);
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				int sum = 0;
				for (int k = 0; k < arr[i][j].size(); k++)
				{
					sum += arr[i][j][k];
				}

				arr[i][j].clear();
				arr[i][j].emplace_back(sum); //먼지양 다시 계산해서 삽입
			}
		}
		UpCycle(R, C, pos[0], arr);
		//print(R, C, arr);
		DownCycle(R, C, pos[1], arr);
		//vector로 만들어진 미세먼지 모두 합쳐서 idx0에 저장후 reset

		//공기 청정기 작동
		
		//상부 - 반시계 방향 순환
		//아래쪽부터 진행

		//print(R, C, arr);
		//하부 - 시계 방향 순환
		T--;
	}

	int sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j][0] != -1)
				sum += arr[i][j][0];
		}
	}
	cout << sum << '\n';
}