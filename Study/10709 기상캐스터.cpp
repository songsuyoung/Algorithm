#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;

	vector<vector<char>> cloud(H,vector<char>(W));
	vector<vector<int>> mins(H, vector<int>(W,-1));

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> cloud[i][j];

			if (cloud[i][j] == 'c')
			{
				mins[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (mins[i][j] == 0)
			{
				int nextC = j + 1;
				while (nextC >= 0 && nextC < W && cloud[i][nextC] != 'c')
				{
					if((mins[i][nextC]==-1)||(mins[i][nextC] > mins[i][nextC - 1] + 1))
						mins[i][nextC] = mins[i][nextC - 1] + 1;
					nextC += 1;
				}
				j = nextC - 1;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << mins[i][j] << ' ';
		}
		cout << '\n';
	}
}