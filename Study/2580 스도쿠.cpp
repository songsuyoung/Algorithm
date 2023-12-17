//��Ʈ��ŷ
//row���� ���� ���ڸ� �����´� 
//3,4�� ������
//-> ������ �ƴ�, ���� ����� ���� 
//3 4 or 4 3 �� �����ؾ���... 
//3�� ���� (O)/ 4(X) => �� Ȯ�� ok�� �� ���� , X�� �� ��Ʈ��ŷ. =>O�� �� 
//4�� ���� (O)/ 3(X) => �� Ȯ�� ok�� �� ���� , X�� �� ��Ʈ��ŷ ����. 
//�Ѵ� ok�� �� return 

#include <iostream>
#include <vector>
using namespace std;

//window -> CSC9
void recursive(vector<vector<bool>>& isVisited, vector<vector<int>>& board, bool& isSuccess, pair<int, int> cur)
{

	if (cur.first >= board.size() || cur.second >= board.size())
	{
		//도착.
		isSuccess = true;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	if (isSuccess == false)
	{
		if (board[cur.first][cur.second] != 0) {
			recursive(isVisited, board, isSuccess, make_pair(cur.first + ((cur.second + 1) / 9), (cur.second + 1) % 9));
			return;
		}
		isVisited[cur.first][cur.second] = true;
		for (int k = 1; k <= 9; k++)
		{
			bool isFail = false;
			//row 체크
			for (int r = 0; r < 9; r++)
			{
				if (board[r][cur.second] == k)
				{
					isFail = true;
					break;
				}
			}
			if (isFail) continue;
			//col 체크
			for (int c = 0; c < 9; c++)
			{
				if (board[cur.first][c] == k)
				{
					isFail = true;
					break;
					//실패
				}
			}
			if (isFail) continue;
			//정사각형 체크
			//1/3 ==> 0*3  5/3 => 1*3 (3) 8/3=>2*3 (6)
			//7
			int row = cur.first / 3 * 3;
			int col = cur.second / 3 * 3;

			for (int r = 0; r < 3; r++)
			{
				if (isFail) break;
				for (int c = 0; c < 3; c++)
				{
					if (board[row + r][col + c] == k)
					{
						//실패
						isFail = true;
						break;
					}

				}
			}
			if (isFail) continue;
			board[cur.first][cur.second] = k;
			recursive(isVisited, board,isSuccess, make_pair(cur.first + ((cur.second + 1) / 9), (cur.second + 1) % 9));
		}
		board[cur.first][cur.second] = 0;
		isVisited[cur.first][cur.second] = false;
	}


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> board(9, vector<int>(9, 0));
	vector<vector<bool>> isVisited(9, vector<bool>(9, 0));

	int cnt = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0) cnt++;
		}
	bool isSuccess = false;
	recursive(isVisited, board,isSuccess, make_pair(0, 0));
}