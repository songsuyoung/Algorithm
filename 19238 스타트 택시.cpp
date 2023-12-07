#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b)
{
	if (a.first.first == b.first.first)
		return a.first.second < b.first.second;
	return a.first.first < b.first.first;

}
//vector의 위치를 리턴하자
int FindMinBfs(int N,int arr[][21],pair<int, int>& curPos, vector<pair<pair<int, int>, pair<int, int>>>& people, bool isRiding[])
{
	bool isVisited[21][21] = {};
	queue<pair<pair<int, int>, int>> q;

	int dist[21][21] = {};
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			dist[i][j] = INT_MAX;
	}
	int rows[4] = { -1,0,1,0 };
	int cols[4] = { 0,-1,0,1 };

	q.push(make_pair(curPos, 0));
	while (!q.empty())
	{
		pair<int, int> pos = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (isVisited[pos.first][pos.second]) continue;

		isVisited[pos.first][pos.second] = true;
		dist[pos.first][pos.second] = cnt;
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next = make_pair(pos.first + rows[i], pos.second + cols[i]);

			if (next.first <= 0 || next.second <= 0 || next.second > N || next.first > N || arr[next.first][next.second] == 1 || isVisited[next.first][next.second]) continue;
			
			q.push(make_pair(next, cnt + 1));
		}
	}

	//가장 작은 위치의 end점을 리턴한다.
	pair<int, int> start = make_pair(INT_MAX,INT_MAX);
	pair<int, int> end = make_pair(INT_MAX,INT_MAX);
	int retIdx = 0;
	int minVal = INT_MAX;
	for (int i =0; i < people.size(); i++)
	{
		if (isRiding[i] == false)
		{
			if (dist[people[i].first.first][people[i].first.second] < minVal)
			{
				start = people[i].first;
				end = people[i].second;
				retIdx = i;
				minVal = dist[people[i].first.first][people[i].first.second];
			}
			else if (dist[people[i].first.first][people[i].first.second] == minVal)
			{
				//행이 더 작아
				if (start.first > people[i].first.first)
				{
					start = people[i].first;
					end = people[i].second;
					retIdx = i;

				}
				else if (start.first == people[i].first.first)
				{
					//행이 같을 경우 열이 더 작은 애로 리셋
					if (start.second >= people[i].first.second)
					{
						start = people[i].first;
						end = people[i].second;
						retIdx = i;
					}
				}
			}
		}
	}
	if (retIdx == 0 && isRiding[retIdx]) return -1;
	isRiding[retIdx] = true;
	return retIdx;
}

int GoTaxiBfs(int N, int K, int arr[][21], pair<int, int>& pos, vector<pair<pair<int, int>, pair<int, int>>>& people)
{
	int numberOfRides = 0;

	bool isVisited[21][21] = {};
	bool isRiding[401] = {}; //20*20 =>400명 태울 수 있음.
	queue<pair<pair<int, int>, int>> q; //위치, 사용량
	q.push(make_pair(pos, K));
	int rows[4] = { -1,0,1,0 };
	int cols[4] = { 0,-1,0,1 };
	bool isEmpty = true;
	int preFuelAmount = 0;
	int endIdx = FindMinBfs(N, arr, pos, people,isRiding); //손님은 1명 이상이기 때문에 -1이 나오지않음
	pair<int, int> end = people[endIdx].second;
	while (!q.empty())
	{
		pair<int, int> pos = q.front().first;
		int amount = q.front().second;
		
		q.pop();
		if (isVisited[pos.first][pos.second]) continue;

		//실패
		if (numberOfRides < people.size() && amount < 0)
		{
			return -1;
		}

		if (isEmpty==false&& end == pos)
		{
			amount=amount+(preFuelAmount - amount) * 2;
			endIdx = FindMinBfs(N, arr, pos, people,isRiding); //손님 없음
			if (endIdx == -1)
			{
				end == make_pair(0, 0);
			}
			else
			{
				end = people[endIdx].second;
			}
			numberOfRides++; //한명 태웠음
			isEmpty = true; //손님 내림
			//이전 queue 모두 없애고, 연료도 변경한다.
			while (!q.empty())
			{
				q.pop();
			}

			//현재 방문 처리 리셋
			for (int j = 1; j <= N; j++)
			{
				for (int k = 1; k <= N; k++)
				{
					isVisited[j][k] = false;
				}
			}
		}
		//성공
		if (numberOfRides == people.size())
		{
			return amount;
		}

		isVisited[pos.first][pos.second] = true;
		if (isEmpty)
		{
			if (isRiding[endIdx] && people[endIdx].first == pos)
			{
				preFuelAmount = amount;
				isEmpty = false;
				//queue에 들어있는 모든 내용물 리셋
				while (!q.empty())
				{
					q.pop();
				}
				//현재 방문 처리 리셋
				for (int j = 1; j <= N; j++)
				{
					for (int k = 1; k <= N; k++)
					{
						isVisited[j][k] = false;
					}
				}
			}
		}

		//택시 이동
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next = make_pair(pos.first + rows[i], pos.second + cols[i]);

			if (next.first <= 0 || next.second <= 0 || next.second > N || next.first > N || arr[next.first][next.second] == 1||isVisited[next.first][next.second]) continue;
			q.push(make_pair(next, amount - 1)); //상하좌우 이동할 시 연료 소비
		}
	}

	return -1;
}
int main()
{

	int N, M, K;
	int arr[21][21] = {};
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j]; //1은 벽
		}
	}

	pair<int, int> pos;
	cin >> pos.first >> pos.second; //택시 시작 위치

	vector<pair<pair<int, int>, pair<int, int>>> v;

	for (int i = 0; i < M; i++)
	{
		int sr, sc, er, ec;
		cin >> sr >> sc >> er >> ec;

		v.push_back(make_pair(make_pair(sr, sc), make_pair(er, ec))); //시작 위치 - 종료 위치
	}

	cout << GoTaxiBfs(N, K, arr,pos, v);
}