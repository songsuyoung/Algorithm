#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//총총 
	
	int N;
	cin>>N;

	bool bIsMeet = false;
	unordered_set<string> name;

	string preB = "";
	for (int i = 0; i < N; i++)
	{
		string A, B;
		cin >> A >> B;

		if (A == "ChongChong" || B == "ChongChong")
		{
			bIsMeet = true;
			name.insert(A);
			name.insert(B);
		}

		if (bIsMeet)
		{
			if (name.count(A) != 0 || name.count(B) != 0)
			{
				name.insert(A);
				name.insert(B);
			}
		}
	}

	cout<<name.size()<<'\n';
}
/*
총총 - jthis 만남 => 춤춘다.

jthis -> jyheo98

jyheo98 -> lms0806

lms0806 -> pichulia

*/