#include <iostream>
#include <queue>
using namespace std;
/*
1.���� ó���� �������� �Ϻ� ĭ�� ��ź�� ��ġ�� ���´�. ��� ��ź�� ��ġ�� �ð��� ����.
2.���� 1�� ���� �������� �ƹ��͵� ���� �ʴ´�.

while
3.���� 1�� ���� ��ź�� ��ġ�Ǿ� ���� ���� ��� ĭ�� ��ź�� ��ġ�Ѵ�. ��, ��� ĭ�� ��ź�� ������ �ְ� �ȴ�. ��ź�� ��� ���ÿ� ��ġ�ߴٰ� �����Ѵ�.
4.1�ʰ� ���� �Ŀ� 3�� ���� ��ġ�� ��ź�� ��� �����Ѵ�.

3�� 4�� �ݺ��Ѵ�.
*/
class Pos
{
public:
	int _sec;
	pair<int, int> _pos;

	Pos(pair<int, int> pos, int sec) : _pos(pos), _sec(sec){}
};

void print(int R,int C, int arr[][202])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] == 0) cout << '.';
			else cout << 'O';
		}
		cout << '\n';
	}
}


int main()
{
	//�������� �Ϻ� ĭ�� ��ź ��ġ ( ��� ��ź ��ġ �ð� == 3)
	//���� 1�� ���� �������� �ƹ��͵� �����ʴ´�. => 2��

	//�� ó�� ������ ��ź ��ġ �ð� 2��, sec=1�� ���� �����Ѵ�.
	int R, C, N;
	cin >> R >> C >> N;

	int arr[202][202] = {};
	//queue<Pos> q;
	for (int i = 0; i < R; i++)
	{
		char tmp;
		for (int j = 0; j < C; j++)
		{
			cin >> tmp;

			if (tmp == 'O')
			{
				arr[i][j] = 2; //3�� ��ġ
			}
		}
	}

	int sec = 1;

	int rows[4] = { -1,1,0,0 };
	int cols[4] = { 0,0,-1,1 };
	queue<pair<int, int>> q;
	while (sec < N)
	{
		//��ź ���� ��ġ
		sec++;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j] == 0)
					arr[i][j] = 3; //��ź�� 3��
				else
					arr[i][j] -= 1;
			}
		}

		//print(R, C, arr);
		if (sec == N) break;
		//��ź 1�� �پ���.
		sec++;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				//3�ʰ� �ƴ� (3�ʴ� ���� ���� ��ź�̱� ������ ����)
				arr[i][j] -= 1; //1�� ���δ�.
				if (arr[i][j] <= 0) {
					q.push(make_pair(i, j));
				}
			}
		}

		while (!q.empty())
		{
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			arr[i][j] = 0;

			for (int k = 0; k < 4; k++)
			{
				int nextR = i + rows[k];
				int nextC = j + cols[k];
				if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C || arr[nextR][nextC] == 0) continue;

				arr[nextR][nextC] = 0;
			}
		}
		//print(R, C, arr);
	}

	print(R, C, arr);

}