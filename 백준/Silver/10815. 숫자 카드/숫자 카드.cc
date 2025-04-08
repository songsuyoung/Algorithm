#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
   cin.tie(0);

   int N;

   cin>>N; //상근이가 들고 있는 숫자카드 개수

   unordered_set<int> sang;

   for (int i = 0; i <N; i++)
   {
		int card;
		cin>>card;

		sang.insert(card);
   }

   int M;
   cin>>M;

   for (int i = 0; i < M; i++)
   {
	   int card;

	   cin>>card;

	   if (sang.find(card) != sang.end())
	   {
		   //있음
		   cout<<"1 ";
	   }
	   else
	   {
		   cout<<"0 ";
	   }
   }

   
}

/*
숫자 카드 N개, M개
*/