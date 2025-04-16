#include <bits/stdc++.h>
using namespace std;

vector<int> GetPossibleNum(vector<int>& num)
{
	vector<bool> isVisited(10,0);

	for (int i = 0; i < num.size(); i++)
	{
		isVisited[num[i]] = true;
	}

	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		if (isVisited[i] == false)
		{
			v.push_back(i);
		}
	}
	return v;
}

void recursive(vector<vector<int>>& sudoku, vector<pair<int, int>>& zero, int idx)
{
	if (idx >= zero.size())
	{
		for (int i = 0; i < sudoku.size(); i++)
		{
			for (int j = 0; j < sudoku.size(); j++)
			{
				cout<<sudoku[i][j]<<' ';
			}
			cout<<"\n";
		}
		exit(0);
	}

	//가질 수 있는 수를 가지고 온다.
	//수를 넣고 행에 대해 검사한다. => 행에서 가질 수 있는 수를 가져오는데? 굳이 검사해야하나?
	vector<int> possible = GetPossibleNum(sudoku[zero[idx].first]);

	for (int j = 0; j < possible.size(); j++)
	{
		//열에 대해서 검사한다.
		int k = 0;
		for (; k < 9; k++)
		{
			if (possible[j] == sudoku[k][zero[idx].second])
			{
				break;
			}
		}

		if (k >= 9)
		{
			//3x3에 대해서 검사한다.
			int r = zero[idx].first / 3;
			int c = zero[idx].second / 3;

			bool bIsSuccess = true;
			for (int st = r * 3; st < (r + 1) * 3; st++)
			{
				for (int ed = c * 3; ed < (c + 1) * 3; ed++)
				{
					if (possible[j] == sudoku[st][ed])
					{
						bIsSuccess = false;
						break;
					}
				}
			}

			if (bIsSuccess)
			{
				//통과하면 다음 idx로 이동한다.
				sudoku[zero[idx].first][zero[idx].second] = possible[j];
				recursive(sudoku, zero, idx + 1);
				sudoku[zero[idx].first][zero[idx].second] = 0;
			}
		}
		else
		{
			//통과하지 않는다면 continue한다.
			continue;
		}
	}

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> sudoku(9, vector<int>(9, 0));

    //비어있음
    vector<pair<int, int>> zero;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];

			if (sudoku[i][j] == 0)
			{
				zero.push_back({i,j});
			}
		}
	}

	recursive(sudoku, zero, 0);
}

/*
- 비어있는 칸의 i, j 저장
- 해당 칸에 숫자를 넣고 행/열에 대해 검사
- 행과 열이 포함된 3x3에 대해 검사
   0-2 / 3-5 / 6-8 크기
- 0/3 => 0 ,0%3 => 0 3-1,3-1 => 2,2
- 6/3 => 2 ,6/3 => 2

3*2,3*2 (시작행/열)
3*(2+1), 3*(2+1) 9-1, 9-1 =>8,8

=> 브루트 폴스로 진행 다 넣어본다.

   * 넣기전에 해당 수를 넣어도 되는지 확인.
      * 행/열/정사각형 검사
   * 넣어도 되면 넣는다.
   * 안되면, continue
   * 뒤에서 넣을 수 있는 수가 없다면, 이전으로 돌아가야한다. (return) => 이전 값을 취소하고 다시 도전해야 함.
*/