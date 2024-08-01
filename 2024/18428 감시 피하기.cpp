#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(int N, vector<vector<char>>& arr)
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << '\n';
}

bool isCheck(int N,vector<vector<char>>& arr,vector<pair<int,int>> teacher)
{
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

//	print(N, arr);

	for (int t = 0; t < teacher.size(); t++)
	{
		for (int i = 0; i < 4; i++)
		{
			int nextR = teacher[t].first;
			int nextC = teacher[t].second;

			while (true)
			{
				nextR += rows[i];
				nextC += cols[i];
				//Object면 막아진 것이니 break;
				if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N || arr[nextR][nextC] == 'O') break; //끝에 도달하였음.
				if (arr[nextR][nextC] == 'S')
				{
					//학생이면
					return false; //오브젝트가 다 못 차지한 것.
				}
			}
		}
	}

	return true;
}


void recursive(int N, vector<vector<char>>& arr, vector<vector<bool>>& isVisited, vector<pair<int, int>> &teacher,int cnt,int r,int c)
{
	if (cnt == 3)
	{
		if (isCheck(N, arr, teacher))
		{
			//성공
			cout << "YES\n";
			exit(0);
		}

		return;
	}

	//3개 고른다

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isVisited[i][j]) continue;

			if (arr[i][j] == 'X')
			{
				arr[i][j] = 'O';
				isVisited[i][j] = true;
				recursive(N, arr, isVisited, teacher, cnt + 1, i, j+1);
				isVisited[i][j] = false;
				arr[i][j] = 'X';
			}
		}
	}
}


int main()
{
	int N;
	cin >> N;

	vector<vector<char>> arr(N,vector<char>(N));
	vector<pair<int, int>> teacher;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 'T')
			{
				teacher.push_back(make_pair(i, j));
			}
		}
	}
	vector<vector<bool>> isVisited(N, vector<bool>(N));
	recursive(N, arr, isVisited, teacher, 0, 0, 0);

	cout << "NO\n";
}