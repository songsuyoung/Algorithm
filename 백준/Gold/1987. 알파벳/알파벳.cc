#include <bits/stdc++.h>
using namespace std;

int rows[4] = {-1,1,0,0};
int cols[4] = {0,0,-1,1};

int answer = 0;

void recursive(const int &R,const int &C,const vector<string>& v, int num, int r, int c, int cnt)
{
	
	answer = max(answer, cnt);
	
	for (int i = 0; i < 4; i++)
	{
		int nextR = rows[i] + r;
		int nextC = cols[i] + c;
	
		if(nextR<0||nextC<0||nextR>=R||nextC>=C) continue;

		if (num & (1 << v[nextR][nextC] - 'A')) continue;
		//선택
		num |= 1 << v[nextR][nextC] - 'A';
		recursive(R,C,v,num, nextR, nextC, cnt + 1);
		//취소
		num &= ~(1<<v[nextR][nextC] - 'A');
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int R, C;
	cin>>R>>C;

	vector<string> v(R);

	for (int i = 0; i < R; i++)
	{
		cin>>v[i];
	}

	//1,1 항상 포함
	recursive(R, C, v, 1<<v[0][0]-'A', 0, 0, 1);

	cout<<answer<<'\n';
}
