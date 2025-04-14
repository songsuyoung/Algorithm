#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first<b.first;
	}
	return a.second > b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;

	cin>>N;

	double sum=0;
	vector<int> arr(N);
	unordered_map<int,int> counting;

	int maxVal = 0, answer = -4500;
	
	for (int i = 0; i < N; i++)
	{
		cin>>arr[i];
		sum+=arr[i];

		counting[arr[i]]++;

		maxVal = max(maxVal, counting[arr[i]]);
	}

	sort(arr.begin(), arr.end());

	int idxCnt = 2;
	
	vector<int> freq;

	for (const auto& c : counting)
	{
		freq.push_back(c.first);
	}

	sort(freq.begin(),freq.end());

	for (int i = 0; i < freq.size(); i++)
	{
		if (maxVal == counting[freq[i]])
		{
			idxCnt--;

			if (idxCnt >= 0)
			{
				answer = freq[i];
			}
		}
	}

	int len = arr.size();

	sum=round(sum/len);

	if (sum == 0)
	{
		sum = 0;
	}

	cout<<sum<<'\n';
	cout<<arr[len /2]<<'\n';
	cout<< answer <<'\n';
	cout<<arr[len -1] - arr[0]<<'\n';
}
