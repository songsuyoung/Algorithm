#include <iostream>
#include <vector>
using namespace std;

/*������ �ð��� ������ ������ 
�ڼ����� ķ������ �� ���� N ���� ���鿹��
�������� K�� ������ ����, but ���̰� ������
N���� ��� ���� ������ �������� ���� ����
�ִ� ���� ���ϱ�, 

K���� �������̰� ������������ max���� �ʰ��ϵ��� ���� �� ���� �׷���� N�� 0��.
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

	return false; //cnt==K�� ��, �ְ� ���̰� �ȴ�.
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
	//K������ ������� mid�� �ʹ� ���� ��... �׷��Ƿ�, left=mid+1�Ѵ�.
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