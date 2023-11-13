#include <iostream>
#include <vector>
using namespace std;

int recursive(int N,int cnt,bool *isVisited,int *arr,int idx)
{
	if (cnt == 3)
	{
		for (int i = 0; i <N; i++)
		{

			int localCnt = 0;
			if (!isVisited[i])
			{
				while (!isVisited[i] && i < N)
				{
					++i;
					++localCnt;
				}

				if (localCnt+3 == N) return 0;
			}
		}
		//true일 때 더하고
		//false일 때 곱함 
		
		int mult = 1,sum=0;
		for (int i = 0; i < N; i++)
		{
			if (isVisited[i])
			{
				sum += arr[i];
				//방문했을 때 더함.
			}
			else {
				mult *= arr[i];
				//방문 안했을 때 곱함
			}
		}
		
		return sum+mult;
	}
	int maxVal = 0;
	for (int i = idx; i < N; i++)
	{
		if (isVisited[i])
			continue;
		isVisited[i] = true;
		maxVal=max(maxVal, recursive(N,cnt+1,isVisited,arr,i));
		isVisited[i] = false;
	}

	return maxVal;
}
int main()
{

	int N;
	cin >> N;

	int arr[11] = {};
	bool isVisited[11] = {};
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cout << recursive(N ,0, isVisited, arr, 0);

	//4개씩 나눈다.
	//10
	// 0 | 1 2 | 3 4 5 6 | 7 8 9
	// 3개를 나눠야하네? 

	//idx -> 끝 pos이라면? cnt 3개가 되면
	//0~idx-1 idx~pos...이런식으로 계산 가능할거같기도?
}