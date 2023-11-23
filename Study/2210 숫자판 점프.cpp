#include <iostream>
#include <string>
#include <map>
using namespace std;

int recursive(map < string, bool> &m,bool isVisited[][5],int arr[][5],string output, int r,int c)
{
	//인접한 4방향을 5번 이동 

	if (output.length() == 6)
	{
		if (m[output])
		{
			return 0;
		}
		m[output] = true;
		return 1;
	}
	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	int res = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + rows[i];
		int nextC = c + cols[i];
		//상하좌우 이동
		if (nextR>=5||nextC>=5||nextR<0||nextC<0) continue;
		res+=recursive(m, isVisited, arr, output + to_string(arr[nextR][nextC]), nextR, nextC);
	}

	return res;
}
int main()
{

	int arr[5][5] = {};
	map<string, bool> m;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			bool isVisited[5][5] = {};
			res+=recursive(m, isVisited, arr, "", i, j);
		}
	}

	cout << res << '\n';
	
}