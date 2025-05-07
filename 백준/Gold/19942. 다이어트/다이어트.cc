#include <bits/stdc++.h>
using namespace std;

pair<int,string> answer(INT_MAX, "987654321");
vector<int> v;
vector<vector<int>> arr[25'005];

void recursive(vector<vector<int>>& cook, vector<int>& target, int idx, int sum, string selected)
{
	if (target[0] <= 0 && target[1] <= 0 && target[2] <= 0 && target[3] <= 0)
	{
		//모두 작을 때 영양분을 채운것.
		
		if (answer.first >= sum)
		{
			answer.first = sum;
			arr[sum].push_back(v);

		}
		return;
	}

	if (cook.size() <= idx)
	{
		//초과할경우 그냥 실패
		return;
	}

	//선택 안한다.
	recursive(cook, target, idx+1, sum, selected);
	// 영양분 채움
	for (int i = 0; i < 4; i++)
	{
		target[i] -= cook[idx][i];
	}

	v.push_back(idx+1);
	// 비트 마스킹으로 무엇을 선택했는지 전달
	recursive(cook, target, idx+1, sum + cook[idx][4], selected + to_string(idx+1)); //가격을 더함
	v.pop_back();

	// 복구
	for (int i = 0; i < 4; i++)
	{
		target[i] += cook[idx][i];
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin>>N;

	// 0: 단백질, 1: 지방 2: 탄수화물 3: 비타민 4: 가격
	vector<vector<int>> cook(N, vector<int>(5, 0));

	//목표치
	vector<int> target(4);
	for (int i = 0; i < 4; i++)
	{
		cin>>target[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin>>cook[i][j];
		}
	}

	recursive(cook, target, 0, 0, "");

	if (answer.first == INT_MAX)
	{
		cout<<"-1\n";

		return 0;
	}
	cout<<answer.first<<'\n';

	sort(arr[answer.first].begin(), arr[answer.first].end());

	for (int i = 0; i < arr[answer.first][0].size(); i++)
	{
		cout<<arr[answer.first][0][i]<<' ';
	}

	/*int idx = 1;
	while (answer.second > 0)
	{
		if (answer.second % 2 == 1)
		{
			cout<<idx<<' ';
		}

		answer.second/=2;
		idx++;
	}*/
}
/*
식재로 N개 중 몇 개를 선택해서 이들의 영양분(단백질/탄수화물/지방/비타민)이 일정 이상이어야함.

6가지 식재료 중 몇 개를 선택해서 이들의 영양분의 각각 합이 최소 100,70,90,10이 되는 경우의 수 => 완전탐색
조건을 만족시키면서, 비용이 최소인 선택

선택 => sum + 가격

min(answer, sum) 업데이트 



184 56

56/2 => 0
28/2 => 0
14/2 => 0
7/2  => 1
3/2  => 1
1

00 0111

0,1,2 => 100 10 70 => 180


28/2 => 14 0
14/2 => 7  0
7/2  => 3  1
3/2  => 1  1


00 111
100 10 120 => 0 1 5

*/