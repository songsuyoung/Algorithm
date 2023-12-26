#include <string>
#include <vector>
using namespace std;
//연결된 puyo 개수 리턴
int connected(int R,int C,vector<string> &field)
{
	vector<vector<bool>> connected(R, vector<bool>(C, false));

	int cnt = 0;
	int rows[4] = { 0,0,1,1 };
	int cols[4] = { 0,1,0,1 };
	for (int i = R-1; i >= 0; i--)
	{
		for (int j = 0; j < C; j++)
		{
			bool isFail = false;

			for (int k = 0; k < 4; k++)
			{
				int nextR = i + rows[k];
				int nextC = j + cols[k];

				if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C||field[nextR][nextC]=='.'||field[i][j]!=field[nextR][nextC])
				{
					isFail = true;
					break;
				}
			}

			if (isFail == false)
			{
				for (int k = 0; k < 4; k++)
				{
					int nextR = i + rows[k];
					int nextC = j + cols[k];
					connected[nextR][nextC] = true;
				}
				cnt++;
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j <C; j++)
		{
			if (connected[i][j])
				field[i][j] = '.'; //물방울 터짐
		}
	}
	return cnt;
}

void fall(int R,int C,vector<string>& field)
{

	for (int c = 0; c < C; c++)
	{
		for (int r = R-1; r >= 0; r--)
		{
			if (field[r][c] != '.')
			{
				while (r+1 < R && field[r+1][c] == '.')
				{
					field[r + 1][c] = field[r][c];
					field[r][c] = '.';
					r = r + 1;
				}
			}
		}
	}

}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true)
    {
        int cnt=connected(m,n,board);
        if(cnt==0) break;
        fall(m,n,board);
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='.') answer++;
        }
    }
    return answer;
}