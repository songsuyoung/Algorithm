#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


void print(vector<vector<int>>& arr, int N)
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}

void move(vector<vector<int>>& arr, int N)
{

	int rows[4] = { -1,0,1,0 };
	int cols[4] = { 0,1,0,-1 };

	int r = N / 2;
	int c = r;
	int cnt = 0,num=1;
	int idx = 0;
	arr[r][c] = num;

	while (true)
	{
		
		if (idx >= 4)
		{
			idx = 0;
		}
		if (idx == 0 || idx == 2)
		{
			cnt++;
		}
	
		for (int i = 0; i < cnt; i++)
		{
			r += rows[idx];
			c += cols[idx];

			if (r < 0 || c < 0 || r >= N || c >= N) continue;
			
			arr[r][c] = ++num;
		}

		if (num>= N * N) break;

		idx++;
	}

}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> arr(N,vector<int>(N,0));

	move(arr, N);

	print(arr, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == M)
			{
				cout << i + 1 << ' ' << j + 1 << '\n';
				return 0;
			}
		}
	}

}