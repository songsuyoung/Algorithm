#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main()
{
	int r, c, k;
	cin >> r >> c >> k;

	vector<vector<int>> arr(3, vector<int>(3, 0));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	int sec = 0;
	while (sec<=100)
	{
		//out of bounds 뜨는 이유 : r,c보다 큰 경우가 있을 수 있음 이를 고려해야함!!(주의주의)
		if (arr.size() >= r && arr[0].size() >= c)
		{
			if (arr[r - 1][c - 1] == k)
			{
				break;
			}
		}

		if (arr[0].size() <= arr.size())
		{
			int maxRow = 0;

			for (int i = 0; i < arr.size(); i++)
			{
				map<int, int> frequency;
				//행에 대해서
				for (int j = 0; j < arr[i].size(); j++)
				{
					if (arr[i][j] == 0) continue;
					frequency[arr[i][j]]++;
				}
				vector<pair<int, int>> number(frequency.begin(), frequency.end());
				vector<int> buf;
				sort(number.begin(), number.end(), compare);

				for (auto num : number)
				{
					if (buf.size() > 100) break;
					buf.push_back(num.first);
					buf.push_back(num.second);
				}

				arr[i].swap(buf);

				if (arr[i].size() > maxRow)
				{
					maxRow = arr[i].size();
				}
			}

			for (int i = 0; i < arr.size(); i++)
			{
				for (int j = arr[i].size(); j < maxRow; j++)
				{
					arr[i].push_back(0);
				}
			}
		}
		else
		{
			//열에 대해서 
			
			int maxCol = 0;
			vector<vector<int>> buf(arr[0].size());

			for (int c = 0; c < arr[0].size(); c++)
			{
				map<int, int> frequency;
				//열에 대해서

				for (int r = 0; r < arr.size(); r++)
				{
					if (arr[r][c] == 0) continue;
					frequency[arr[r][c]]++; //[3,1,1] -> 3 1 1 2
				}

				vector<pair<int, int>> number(frequency.begin(), frequency.end());
				sort(number.begin(), number.end(), compare);

				//tmp [3 1 1 2] => 정렬
				for (auto num : number)
				{
					if (buf[c].size() > 100) break;
					buf[c].push_back(num.first);
					buf[c].push_back(num.second);
				}

				if (buf[c].size() > maxCol)
				{
					maxCol = buf[c].size();
				}
			}

			for (int r = 0; r < buf.size(); r++)
			{
				for (int i = buf[r].size(); i < maxCol; i++)
				{
					buf[r].push_back(0);
				}
			}

			vector<vector<int>> arr2(buf[0].size(), vector<int>(buf.size()));
			//buf 행 arr 열로
			for (int i = 0; i < buf.size(); i++)
			{
				for (int j = 0; j < buf[i].size(); j++)
				{
					arr2[j][i] = buf[i][j];
				}
			}
			arr.swap(arr2);
		}

		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = 0; j < arr[i].size(); j++)
			{
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		sec++;
	}

	if (sec > 100)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << sec << '\n';
	}
}