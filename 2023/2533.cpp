#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recursive(vector<vector<int>>& v, vector<vector<int>> &dp,vector<bool> &isVisited, bool selected, int idx)
{

	int selectedCnt = 0, notSelectedCnt = INT_MAX;
	
	if (dp[selected][idx] != -1) return dp[selected][idx];
	isVisited[idx] = true;

	if (selected == true) //부모가 선택된 경우
	{
		notSelectedCnt = 0;
		for (int i = 0; i < v[idx].size(); i++)
		{
			if(isVisited[v[idx][i]]==false)
				notSelectedCnt += recursive(v, dp,isVisited,false, v[idx][i]);
		}
	}

	for (int i = 0; i < v[idx].size(); i++)
	{
		if (isVisited[v[idx][i]] == false)
			//부모가 선택되지 않은 경우
			selectedCnt += recursive(v, dp, isVisited, true, v[idx][i]);
	}

	isVisited[idx] = false; //선택을 풀어서, 다른 경우의 수도 확인
	return dp[selected][idx]=min(selectedCnt + 1, notSelectedCnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;

	vector<vector<int>> v(N + 1);
	vector<vector<int>> dp(2,vector<int>(N + 1,-1));
	for (int i = 0; i < N - 1; i++)
	{
		int p, c;
		cin >> p >> c;

		v[p].push_back(c);
		v[c].push_back(p);
	}

	vector<bool> isVisited(N + 1, false);
	int selected = recursive(v, dp,isVisited, true, 1);

	cout << selected << '\n';
}