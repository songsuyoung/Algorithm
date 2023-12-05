#include <iostream>
#include <vector>
using namespace std;

void print(int R, int C, vector<int> arr[][51])
{
	cout << '\n';
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << arr[i][j][0] << ' ';
		}
		cout << '\n';
	}
}

void UpCycle(int R,int C, pair<int, int>& pos,vector<int> arr[][51])
{

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	for (int r = pos.first - 1; r > 0; r--)
	{
		//�Ʒ��� �̵�
		arr[r][pos.second][0] = arr[r-1][pos.second][0];
	}

	//���ʺ��� ����
	for (int c = 0; c < C - 1; c++)
	{
		arr[0][c][0] = arr[0][c + 1][0];
	}

	//���� ����
	for (int r = 0; r < pos.first; r++)
	{
		arr[r][C - 1][0] = arr[r + 1][C - 1][0];
	}

	//����������
	for (int c = C - 1; c > 0; c--)
	{
		arr[pos.first][c][0] = arr[pos.first][c - 1][0];
	}
	//����û���⿡�� �δ� �ٶ��� �̼������� ���� �ٶ���
	arr[pos.first][1][0] = 0;
}

void DownCycle(int R, int C, pair<int, int> &pos, vector<int> arr[][51])
{
	for (int r = pos.first + 1; r < R-1; r++)
	{
		//���� �̵�
		arr[r][pos.second][0] = arr[r+1][pos.second][0];
	}

	//���ʺ��� ����
	for (int c = 0; c < C - 1; c++)
	{
		arr[R-1][c][0] = arr[R-1][c + 1][0];
	}

	//�Ʒ��� ����
	for (int r = R-1; r > pos.first; r--)
	{
		arr[r][C - 1][0] = arr[r - 1][C - 1][0];
	}

	//����������
	for (int c = C - 1; c > 0; c--)
	{
		arr[pos.first][c][0] = arr[pos.first][c - 1][0];
	}
	//����û���⿡�� �δ� �ٶ��� �̼������� ���� �ٶ���
	arr[pos.first][1][0] = 0;
}

int main()
{
	int R, C, T;

	cin >> R >> C >> T;
	vector<int> arr[51][51] = {};
	
	vector<pair<int, int>> pos = {};

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int val;
			cin >> val;

			arr[i][j].push_back(val);
			
			if(val==-1)
			{
				pos.push_back(make_pair(i, j)); //��� �Ϻο� ���� row/col����
			}
		}
	}

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };

	while (T > 0)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				int amount = arr[i][j][0] / 5;
				int cnt = 0;
				//r,c�� �ִ� �̼������� ������ �׹������� Ȯ��
				for (int k = 0; k < 4; k++)
				{
					int nextR = i + rows[k];
					int nextC = j + cols[k];
					//������ ���⿡ ����û���Ⱑ �ְų� ĭ�̾����� Ȯ�� ���
					if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C || arr[nextR][nextC][0] == -1) continue;
					cnt++;
					arr[nextR][nextC].push_back(amount);
				}
				arr[i][j][0] -= (amount * cnt);
				//A(r,c)/5
				//A(r,c)=A(r,c)-(A(r,c)/5*N)
			}
		}
		//print(R, C, arr);
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				int sum = 0;
				for (int k = 0; k < arr[i][j].size(); k++)
				{
					sum += arr[i][j][k];
				}

				arr[i][j].clear();
				arr[i][j].emplace_back(sum); //������ �ٽ� ����ؼ� ����
			}
		}
		UpCycle(R, C, pos[0], arr);
		//print(R, C, arr);
		DownCycle(R, C, pos[1], arr);
		//vector�� ������� �̼����� ��� ���ļ� idx0�� ������ reset

		//���� û���� �۵�
		
		//��� - �ݽð� ���� ��ȯ
		//�Ʒ��ʺ��� ����

		//print(R, C, arr);
		//�Ϻ� - �ð� ���� ��ȯ
		T--;
	}

	int sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j][0] != -1)
				sum += arr[i][j][0];
		}
	}
	cout << sum << '\n';
}