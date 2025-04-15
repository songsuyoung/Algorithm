#include <bits/stdc++.h>
using namespace std;

vector<bool> isVisited(10, false);
vector<int> num;
void recursive(int N, int M)
{
	if (M <= 0)
	{
		for (int i = 0; i < num.size(); i++)
		{
			cout<<num[i]<<' ';
		}
		cout<<"\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		num.push_back(i);
		recursive(N, M - 1);
		num.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int N,M;
	cin>>N>>M;

	recursive(N, M);

}
