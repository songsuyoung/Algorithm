#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int N;
	cin>>N;

	vector<int> arr(N,0);
	vector<int> cache(N,0);

	for (int i = 0; i < arr.size(); i++)
	{
		cin>>arr[i];
	}

	stack<int> st;
	for (int i = 0; i < N; i++) //O(N)
	{
		while (st.empty() == false && arr[st.top()] < arr[i]) 
		{
			cache[st.top()] = arr[i];
			st.pop();
		}

		st.push(i);
	}

	while (st.empty() == false)
	{
		cache[st.top()] = -1;
		st.pop();
	}

	for (int i = 0; i < N; i++)
	{
		cout<<cache[i]<<' ';
	}

}
/*
크기가 N인 수열

오큰수 NGE(i)

예를 들어, 3 5 2 7
            1   2

오큰수 1

stack을 활요하면 어떨까?

3 < 5

5 출력

5 < 7
7 출력 => i인덱스 => 큰 수를 7 삽입 arr[st.top()] < arr[i]
cache[st.top()] = arr[i]; 이런식으로..

2 < 7
위처럼 삽입.


=> stack 1번 돌기 때문에 O(N)?
*/
