#include <bits/stdc++.h>
using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;

	cin>>N;
	//stack
	stack<int> stk;

	int sortingVal = 1;
	for (int i = 0; i < N; i++)
	{
		int order;
		cin>>order;

		if (order != sortingVal)
		{
			while (!stk.empty() && stk.top() == sortingVal)
			{
				stk.pop();
				sortingVal++;
			}

			stk.push(order);
		}
		else
		{
			sortingVal++;
		}
	}

	while (!stk.empty() && stk.top() == sortingVal)
	{
		stk.pop();
		sortingVal++;
	}

	if (stk.empty())
	{
		cout<<"Nice\n";
	}
	else
	{
		cout<<"Sad\n";
	}
}