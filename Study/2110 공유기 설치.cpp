#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*�������� �� N�� ������ ���� ����.
�� ��ǥ x1,...xN�̰� ������ ��ǥ�� ���� �� ����
�������� ���� ���� ���� C�� ��ġ�ҷ��� 
������ ������ �ϳ��� ��ġ ���� 
���� ������ �� ������ ������ �Ÿ��� ������ ũ�� ��ġ

���� �� 5��, ������ 3�� ���ƾ��� (1+10)/2 = 5

*        *     => 2�� right=4 (1+4)/2 => 2
1  2  4  8  9
*     *  *     => 3�� left=2 (2+4)/2 => 3             left=3+4 (7/2) 
*/

bool isPutting(int C, vector<int>& wifi, long long dis)
{
	int cnt = 1;
	//���� ù��° ������ �� �����⸦ ��ġ 
	//wifi �迭�� ������ ������ 
	int fixed = 0;
	for (int i = 0; i < wifi.size();i++)
	{
		if (abs(wifi[i] - wifi[fixed]) >= dis)
		{
			cout << wifi[i] << ' ' << wifi[fixed] << " : " << dis << '\n';
			fixed = i;
			cnt++;
			continue;
		}
	}
	cout << "�� ���� " << cnt << '\n';
	return cnt >= C;
}
int main()
{

	int N, C;
	cin >> N >> C;

	vector<int> wifi;

	long long left = 1, right = 0;
	
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		wifi.push_back(tmp);
		if (tmp > right)
			right = tmp; //���� �� �ִ� ���� ū ��ġ
	}
	
	long long dis = 0;
	long long limits = right;
	
	sort(wifi.begin(), wifi.end());
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (isPutting(C, wifi, mid))
		{
			dis = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << dis << '\n';
}