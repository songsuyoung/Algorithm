#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*도현이의 집 N개 수직선 위에 있음.
집 좌표 x1,...xN이고 여러개 좌표를 가질 일 없음
와이파이 즐기기 위해 공유 C개 설치할려함 
한집에 공유기 하나만 설치 ㄱㄴ 
가장 인접한 두 공유기 사이의 거리를 가능한 크게 설치

예시 집 5개, 공유기 3개 놓아야함 (1+10)/2 = 5

*        *     => 2개 right=4 (1+4)/2 => 2
1  2  4  8  9
*     *  *     => 3개 left=2 (2+4)/2 => 3             left=3+4 (7/2) 
*/

bool isPutting(int C, vector<int>& wifi, long long dis)
{
	int cnt = 1;
	//가장 첫번째 집에는 꼭 공유기를 설치 
	//wifi 배열에 속하지 않으면 
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
	cout << "총 개수 " << cnt << '\n';
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
			right = tmp; //놓을 수 있는 가장 큰 위치
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