#include <bits/stdc++.h>
using namespace std;

vector<int> buf;

void merge(int A, int* arr, int l, int mid, int r)
{
	int p = l;
	int q = mid + 1;
	int t=0;

	int *temp = new int[A+1];

	while (p <= mid && q <= r)
	{
		//값이 작은 것부터 삽입
		if (arr[p] <= arr[q])
		{
			temp[t++] = arr[p++];
		}
		else
		{
			temp[t++] = arr[q++];
		}
	}

	while (p <= mid)
	{
		temp[t++] = arr[p++];
	}

	while (q <= r)
	{
		temp[t++] = arr[q++];
	}

	//덮어쓰기

	for (int i = l,t=0; i <= r; i++,t++)
	{
		arr[i] = temp[t];

		buf.push_back(arr[i]);
	}

	delete temp;
}

/*
merge sort 는 분할 정복방식의 알고리즘
*/
void merge_sort(int A, int *arr, int l, int r)
{
	if (l < r)
	{
		int mid = (l + r)/2;

		merge_sort(A, arr, l, mid); //분할
		merge_sort(A, arr, mid + 1, r); //분할
		merge(A, arr,l,mid,r); //정복
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, K;

	cin>>A>>K;

	int *arr = new int[A+1];

	for (int i = 0; i < A; i++)
	{
		cin>>arr[i];
	}

	merge_sort(A, arr, 0, A-1);

	if (buf.size() < K)
	{
		cout<<-1<<'\n';
	}
	else
	{
		cout << buf[K - 1] << '\n';
	}

	delete arr;
}
