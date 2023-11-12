#include <iostream>
#include <vector>
using namespace std;


/*
긴 배열 중 
1.현재 idx를 선택안할지 -> 이전 값을 전달하면 된다 f(n-1)
2.현재 idx를 선택할지 -> f(n)를 return한다.
3.이전에 선택한 idx보다 커서 선택하지 못할시, 
 - 자신보다 큰 값을 가진 idx 중 가장 긴 횟수를 가지고 있는 idx를 찾아 현재 자신 값을 합쳐 1번과 비교 후 return한다. 

* 리턴 값)
  * 현재 선택된 개수를 return 해야함.
  * 선택된 idx보다 현재 idx가 작은지 확인하기 위해서 선택된 idx를 return해야함.
 */

pair<int, int> recursive(vector<int>& v,int dp[], int idx)
{
	if (idx == (v.size() - 1)) {
		dp[idx] = 1;
		return make_pair(idx, dp[idx]); //현재 선택된 idx 전달
	}

	pair<int, int> res = recursive(v,dp, idx + 1); //현재 선택된 idx보다 idx값이 작을 때 선택해서 return

	if (v[res.first] > v[idx])
	{
		dp[idx] = res.second + 1;
		return make_pair(idx, dp[idx]);
	}

	//O(N)해결하기 위해서, 현재 idx가 선택할 수 있는 값 중 가장 큰 dp값을 가진 값 선택.
	int max=0;
	for (int i = idx+1; i < v.size(); i++)
	{
		if (v[idx] < v[i]&&max<dp[i])
		{
			max = dp[i];
		}
	}

	dp[idx] = max + 1;
	return res.second > max ? res : make_pair(idx, dp[idx]);
}
int main()
{

	//idx에 대한 vector<pair<int,int>> dp 일듯? 
	// 각 idx에 대해 몇번 갈 수 있는지 횟수... 
	int dp[1005] = {};
	vector<int> v;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	cout << recursive(v, dp, 0).second << '\n';
}