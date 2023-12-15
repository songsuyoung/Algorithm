#include <iostream>
#include <vector>
using namespace std;

/*dp가 필요한 이유: 데이터 1000개 -> recursive에 의해 1000개로 뻗어 나감, 만약
결과가 자신보다 큰 값이 아니라면, 자신보다 큰 값 중 상자 개수를 가져와야함 (이때 반복문 1000^2번 수행)
따라서 n중 for문 수행=> 따라서 dp를 이용해서 카운트를 저장한 후, 가장 큰 값을 가져오는 방법 사용 */

pair<int,int> recursive(const vector<int> &boxs,vector<int> &dp,int idx)
{
	if (idx == boxs.size() - 1)
	{
		return make_pair(boxs[idx], dp[idx]);
	}

	//이전에 돌아온 것이 가장 큰 값
	pair<int,int> pre=recursive(boxs, dp, idx+1);
	if (boxs[idx] < pre.first)
	{
		dp[idx] += pre.second;
		return make_pair(boxs[idx], dp[idx]);
	}

	for (int i = idx+1; i < boxs.size(); i++)
	{
		if (boxs[idx] < boxs[i]&&dp[idx] <= dp[i])
		{
			dp[idx] = dp[i]+1;
		}
	}

	return pre.second>dp[idx]? pre: make_pair(boxs[idx], dp[idx]);
}
int main()
{
	int N;
	cin >> N;

	vector<int> boxs;

	for (int i = 0; i < N; i++)
	{
		int size;
		cin >> size;
		boxs.push_back(size);
	}

	vector<int> dp(boxs.size(), 1);
	
	cout<<recursive(boxs, dp, 0).second<<'\n';
}