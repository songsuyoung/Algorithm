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
		//true�� �� ���ϰ�
		//false�� �� ���� 
		
		int mult = 1,sum=0;
		for (int i = 0; i < N; i++)
		{
			if (isVisited[i])
			{
				sum += arr[i];
				//�湮���� �� ����.
			}
			else {
				mult *= arr[i];
				//�湮 ������ �� ����
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

	//4���� ������.
	//10
	// 0 | 1 2 | 3 4 5 6 | 7 8 9
	// 3���� �������ϳ�? 

	//idx -> �� pos�̶��? cnt 3���� �Ǹ�
	//0~idx-1 idx~pos...�̷������� ��� �����ҰŰ��⵵?
}