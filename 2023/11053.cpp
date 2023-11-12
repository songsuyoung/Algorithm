#include <iostream>
#include <vector>
using namespace std;


/*
�� �迭 �� 
1.���� idx�� ���þ����� -> ���� ���� �����ϸ� �ȴ� f(n-1)
2.���� idx�� �������� -> f(n)�� return�Ѵ�.
3.������ ������ idx���� Ŀ�� �������� ���ҽ�, 
 - �ڽź��� ū ���� ���� idx �� ���� �� Ƚ���� ������ �ִ� idx�� ã�� ���� �ڽ� ���� ���� 1���� �� �� return�Ѵ�. 

* ���� ��)
  * ���� ���õ� ������ return �ؾ���.
  * ���õ� idx���� ���� idx�� ������ Ȯ���ϱ� ���ؼ� ���õ� idx�� return�ؾ���.
 */

pair<int, int> recursive(vector<int>& v,int dp[], int idx)
{
	if (idx == (v.size() - 1)) {
		dp[idx] = 1;
		return make_pair(idx, dp[idx]); //���� ���õ� idx ����
	}

	pair<int, int> res = recursive(v,dp, idx + 1); //���� ���õ� idx���� idx���� ���� �� �����ؼ� return

	if (v[res.first] > v[idx])
	{
		dp[idx] = res.second + 1;
		return make_pair(idx, dp[idx]);
	}

	//O(N)�ذ��ϱ� ���ؼ�, ���� idx�� ������ �� �ִ� �� �� ���� ū dp���� ���� �� ����.
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

	//idx�� ���� vector<pair<int,int>> dp �ϵ�? 
	// �� idx�� ���� ��� �� �� �ִ��� Ƚ��... 
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