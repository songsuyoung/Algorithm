#include <iostream>
#include <vector>
using namespace std;

/*집에서 시간을 보내던 오영식 
박성원이 캠프에서 쓸 랜선 N 개를 만들예정
오영식은 K개 랜선이 있음, but 길이가 제각각
N개를 모두 같은 길이의 랜선으로 만들 예정
최대 랜선 구하기, 

K개의 랜선길이가 제각각이지만 max값을 초과하도록 만들 수 없음 그럴경우 N이 0임.
*/

bool isUsing(int K,vector<int> &lan,int cm)
{
	long long cnt = 0;

	for (int i = 0; i < lan.size(); i++)
	{
		int tmp = lan[i];
		while (tmp-cm >= 0)
		{
			tmp -= cm;
			cnt++;
			if (cnt == K)
				return true;
		}
	}

	return false; //cnt==K일 때, 최고 길이가 된다.
}
int main()
{

	int N, K;
	cin >> N >> K;

	long long left=1, right=0;
	vector<int> lan;
	for (int i = 0; i < N; i++)
	{
		long long tmp;
		cin >> tmp;
		lan.push_back(tmp);

		if (tmp > right)
			right = tmp;
	}

	long long cm = 0;
	//K개보다 많을경우 mid가 너무 작은 것... 그러므로, left=mid+1한다.
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (isUsing(K, lan, mid))
		{
			cm = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << cm << '\n';
}