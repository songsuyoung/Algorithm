#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> arr(N);
	set<int> st;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		st.insert(arr[i]);
	}

	unordered_map<int, int> sorting;

	int idx=0;
	for (const auto& order : st)
	{
		sorting[order] = idx;
		idx++;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout<<sorting[arr[i]] << ' ';
	}
}

//수, 빈도, 순위
//수 정렬 => 순위 (map=> 정렬)
//실제 수 보관 vector