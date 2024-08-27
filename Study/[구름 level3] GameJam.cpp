#include <bits/stdc++.h>
using namespace std;

bool move(int N,pair<int,int> &curPlayer, int dir,int count, vector<vector<bool>> &isVisited)
{
	int rows[] = {-1,1,0,0};
	int cols[] = {0,0,1,-1};
	
	for(int i=0;i<count;i++)
	{
		curPlayer.first += rows[dir]; //음수도 체크
		curPlayer.second += cols[dir];
		
		if(curPlayer.first<0)
		{
			curPlayer.first = N-1;
		}
		if(curPlayer.first>=N)
		{
			curPlayer.first = 0;
		}
		
		if(curPlayer.second>=N)
		{
			curPlayer.second = 0;
		}
		if(curPlayer.second<0)
		{
			curPlayer.second = N-1;
		}
		
		if(isVisited[curPlayer.first][curPlayer.second]) return false; //실패
		isVisited[curPlayer.first][curPlayer.second] = true;
	}
	
	return true;
}

pair<int,int> translate(string command)
{
	
	string num = command.substr(0,command.length()-1);
	char dir= command[command.length()-1];
	int dirIdx=0;
	switch(dir)
	{
			case 'U':
			dirIdx = 0;
			break;
			case 'D':
			dirIdx = 1;
			break;
			case 'R':
			dirIdx = 2;
			break;
			case 'L':
			dirIdx = 3;
			break;
	}
	
	return {atoi(num.c_str()),dirIdx};
}
pair<string,int> calculate(int N, vector<vector<bool>> &gVisited,vector<vector<bool>> &pVisited)
{
	int gcount = 0;
	int pcount = 0;
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(gVisited[i][j]) gcount++;
			if(pVisited[i][j]) pcount++;
		}
	}
	
	pair<string,int> res = {"goorm",gcount};
	
	if(pcount>gcount)
	{
		res.first = "player";
		res.second = pcount;
	}
	
	return res;
}
void play(int N, vector<vector<string>> &commands, pair<int,int> curPlayer, vector<vector<bool>> &visited)
{
	visited[curPlayer.first][curPlayer.second]=true;
	while(true)
	{
		string command = commands[curPlayer.first][curPlayer.second];
		pair<int,int> dirAndCount = translate(command);
		bool playerRes =  move(N,curPlayer,dirAndCount.second,dirAndCount.first,visited);	
		if(playerRes == false) break;
	}
	
}
	//N^2
	//1. command 방향으로 count칸만큼 한칸씩 이동
	//처음 보드 칸 하나에 말을 올림.
	//2. 보드 밖으로 나가면 반대쪽 첫번째로 이동 (mod연산 필요)
	//이동거리가 날아있다면 계속 이동
	//자신의 말이 이미 한번이라도 방문한 칸일 시 종료
	//게임 점수 : 이동한 칸 (방문 처리 필요)
int main() {
	
	int N;
	cin>>N;
	int Rg,Cg; //구름이가 말을 올려둔 칸
	cin>>Rg>>Cg;
	int Rp,Cp;
	cin>>Rp>>Cp;
	
	vector<vector<string>> command(N,vector<string>(N));
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>command[i][j];
		}
	}
	
	vector<vector<bool>> gVisited(N,vector<bool>(N,false));
	vector<vector<bool>> pVisited(N,vector<bool>(N,false));
	
	play(N, command,make_pair(Rg-1,Cg-1),gVisited);
	play(N, command,make_pair(Rp-1,Cp-1),pVisited);
	
	pair<string,int> res=calculate(N,gVisited,pVisited);
	cout<<res.first<<' '<<res.second;
	return 0;
}