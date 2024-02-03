#include <iostream>
#include <vector>
using namespace std;

int recursive(int N,int tri[][505], vector<vector<int>>& dp,int r,int c,int level)
{

	if (level+1 >= N)
		return tri[r][c];

	if (dp[r][c] != 0)
		return dp[r][c];

	//왼쪽 - 오른쪽 큰 것 중 하나를 골라서 return
	dp[r][c] = tri[r][c] + max(recursive(N, tri, dp, r + 1, c, level + 1), recursive(N, tri, dp, r + 1, c + 1, level + 1));
	
	return dp[r][c];

}
int main()
{
	int N;

	int tri[505][505] = {0,};
	cin >> N;

	//       00
	//     10  11
	//   20  21  22
	//  30  31  32  33
	//40  41  42  43  44
	vector<vector<int>> dp;
	for (int i = 0; i < N; i++)
	{
		vector<int> level;
		for (int j = 0; j <= i; j++)
		{
			cin >> tri[i][j];
			level.push_back(0);
		}
		dp.push_back(level);
	}

	cout << recursive(N, tri,dp, 0, 0, 0);
}