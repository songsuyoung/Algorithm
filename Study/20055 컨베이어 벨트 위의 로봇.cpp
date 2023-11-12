#include <iostream>
#include <deque>
using namespace std;

int main()
{

	int N, K;
	cin >> N >> K; //N-1�� �ⱸ, K���� 0���� Ȯ���ؾ���

	deque<pair<int, bool>> belt; //cnt,�κ� ���� 

	for (int i = 0; i < N*2; i++)
	{
		int tmp;
		cin >> tmp;
		belt.push_back(make_pair(tmp, false)); //0(�Ա�) 1 2(�ⱸ) | 3 4 5
		//�ʱ⿡ �κ� ����
	}
	int cnt = 0;
	while (true)
	{
		int endCnt = K;
		cnt++;
		//�̵� 
		pair<int, int> last = belt.back();
		belt.pop_back(); //�������� ����
		belt.push_front(last); //������ ��ġ�� ù��°�� �̵���.

		belt[N - 1].second = false;
		//1. ���� ���� �ö� �κ�����, ��ĭ�� �̵���.
		for (int i = N-2; i >= 0; i--) //�κ��� �ö� �� �ִ� �� N����
		{
			//���� ��ġ�� �κ��� �����鼭, �̵��� ��ġ(i+1)�� �κ��� �������� �ʾƾ���
			if ((belt[i].second==true)&&(belt[i+1].second == false)&&belt[i+1].first >=1)
			{
				//�κ� �̵�
				belt[i].second = false; //���� ��ġ�� �κ��� ���� ��ġ �κ����� �̵�
				belt[i + 1].first -= 1; //������ 1����
				belt[i + 1].second = true; 
			}
		}
	
		// ������ ĭ�� �ִ� �ִ� �׻� ������.
		//2. ��Ʈ�� �� ĭ���� �ִ� �κ��� �Բ� �̵� 
		//�������� 0�� �ƴϸ�, 0��°�� �κ��� �ö�.
		if(belt.front().first>0)
		{
			belt.front().first -= 1;
			belt.front().second = true; //�κ� �ö�
		}
		belt[N - 1].second = false;

		for (int i = 0; i < 2 * N; i++)
		{
			if (belt[i].first <= 0)
				endCnt--;
		}

		if (endCnt <= 0) break;
	}

	cout << cnt << '\n';
}