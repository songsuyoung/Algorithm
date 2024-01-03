/*
목표 upperIdx는 가만히 두고, command값을 입력 받을때마다
주사위의 value를 변경할 예정
*/
#include <iostream>
#include <vector>
using namespace std;

class Dice
{
public:

	Dice(int inX,int inY) : x(inX),y(inY)
	{
		//0번 인덱스 사용 안할 예정.
		dice = vector<int>(7, 0);
	}
	vector<int> dice; //주사위 값 배열 저장
	int x, y; //현재 주사위 좌표

	int GetUpperValue()
	{
		return dice[1];
	}

	//주사위를 굴린다.
	void RollTheDice(int command)
	{
		//command(2) 3->1 1->4 4->3
		// 2->1 1->0 0->2
		//command(1) 4->1 1->3 3->4 
		// 0->1 1->2 2->0
		//command(3) 6->5 5->1 1->2 2->6
		//command(4) 5->5 6->2 2->1 1->5
		// 3->0 2->3 1->2 0->1

		vector<int> westAndeast = { 1, 3, 6, 4 };
		vector<int> northAndSouth = { 2, 1, 5, 6};
		vector<int> buffer(7, 0);
		int size = buffer.size();

		switch (command)
		{
		case 1: //동쪽으로
			size = westAndeast.size();
			for (int i = 0; i < size; i++)
			{
				int idx = (i + 1) % size;
				buffer[westAndeast[idx]] = dice[westAndeast[i]];
			}
			for (int i = 0; i < westAndeast.size(); i++)
			{
				dice[westAndeast[i]] = buffer[westAndeast[i]];
			}
			break;
		case 2: //서쪽으로
			//0->2  0-1 =-1   (2+0)%3 => 2
			//2->1  2-1 =1    (2+2)%3 => 1
			//1->0  1-1=0     (2+1)%3 => 0
			size = westAndeast.size();
			for(int i=0;i< size;i++)
			{
				int idx = ((size - 1) + i) % size;
				buffer[westAndeast[idx]] = dice[westAndeast[i]];
			}
			//주사위 내용물을 변경하기 때문에 항상 밑면은 6을 의미
			for (int i = 0; i < westAndeast.size(); i++)
			{
				dice[westAndeast[i]] = buffer[westAndeast[i]];
			}
			break;
		case 3: //북쪽으로
			// 0->3 1->0 2->1 3->2
			// (6->5, 5->1, 1->2, 2->6)
			//idx=3-i  
			//3=(3+0)%4   0=(3+1)%4 1=(3+2)%4 2=(3+3)%4
			size = northAndSouth.size();
			for (int i = 0; i < size; i++)
			{
				int idx = ((size-1) + i) % size;
				buffer[northAndSouth[idx]] = dice[northAndSouth[i]];
			}
			//주사위 내용물을 변경하기 때문에 항상 밑면은 6을 의미
			for (int i = 0; i < northAndSouth.size(); i++)
			{
				dice[northAndSouth[i]] = buffer[northAndSouth[i]];
			}
			break;
		case 4: //남쪽으로
			//2 ->1-> 5-> 6 ->2
			// 0->1 1->2 2->3 3->4
			size = northAndSouth.size();
			for (int i = 0; i < size; i++)
			{
				int idx = (i + 1) % size;
				buffer[northAndSouth[idx]] = dice[northAndSouth[i]];
			}
			//주사위 내용물을 변경하기 때문에 항상 밑면은 6을 의미
			for (int i = 0; i < northAndSouth.size(); i++)
			{
				dice[northAndSouth[i]] = buffer[northAndSouth[i]];
			}
			break;
		}


	}
	//주사위에 복사한다.
	void CopyTheValue(vector<vector<int>>& board, int command)
	{
		//명령 1,2,3,4 로 이루어지기 때문에 0번째 idx는 임의로 쓰레기값 삽입
		int rows[5] = { 0, 0, 0, -1, 1 };
		int cols[5] = { 0, 1, -1, 0, 0 };

		x = x + rows[command];
		y = y + cols[command];

		if (board[x][y] != 0)
		{
			dice[6] = board[x][y];
			board[x][y] = 0;
		}
		else
		{
			//board가 0인 경우에는
			board[x][y] = dice[6]; //밑면 칸이 복사
		}
		cout << GetUpperValue() << '\n';
	}
};

bool isGoing(Dice& dice, int command, int N, int M)
{
	int rows[5] = { 0, 0, 0, -1, 1 };
	int cols[5] = { 0, 1, -1, 0, 0 };

	int row = dice.x + rows[command];
	int col = dice.y + cols[command];

	if (row >= N || row < 0 || col >= M || col < 0) return false;

	return true;
}

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0);
	//x,y는 현재 주사위 좌표
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;

	vector<vector<int>> board(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	Dice dice(x,y);
	for (int i = 0; i < K; i++)
	{
		int command;
		cin >> command;

		if (isGoing(dice,command,N,M))
		{
			dice.RollTheDice(command);
			dice.CopyTheValue(board, command);
		}
	}
}

/*
4 2 0 0 1
0 2
3 4
5 6
7 8
4

4 2 0 0 4
0 2
3 4
5 6
7 8
4 4 4 1
*/