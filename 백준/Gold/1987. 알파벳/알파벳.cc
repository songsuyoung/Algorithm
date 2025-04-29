#include <bits/stdc++.h>
using namespace std;
vector<bool> isVisited(27,0); //english 개수 26개 -'A'로 방문 처리

int rows[4] = {-1,1,0,0};
int cols[] = {0,0,-1,1};
int DFS(vector<string>& board, int r, int c)
{

	int maxVal = 0;
	
	for (int i = 0; i < 4; i++)
	{
		int nextR = r + rows[i];
		int nextC = c + cols[i];

		if (nextR < 0 || nextR >= board.size() || nextC < 0 || nextC >= board[0].size()) continue;

		char next = board[nextR][nextC];
		if(isVisited[next-'A']) continue;

		isVisited[next - 'A'] = true;
		maxVal = max(maxVal, DFS(board, nextR, nextC) + 1);
		isVisited[next - 'A'] = false;
	}

	return maxVal;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int R,C;
	cin>>R>>C;

	vector<string> board(R);

	for (int i = 0; i < R; i++)
	{
		cin>>board[i];
	}

	//좌측 상단에서 시작
	char cur = board[0][0];
	isVisited[cur - 'A'] = true;
	cout<< DFS(board, 0, 0) + 1 <<'\n'; //자기 자신을 추가해야함.

}


/*
세로 R/가로 C칸으로 된 보드가 존재
대문자 알파벳이 하나씩 적혀 있고 , 상하좌우 이동이 가능
새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과 달라야함. => 방문처리(알파벳에 대해)
최대 몇칸 까지 갈 수 있는가? => DFS
*/