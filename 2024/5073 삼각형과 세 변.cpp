#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	
	while (true)
	{
		vector<int> v(3, 0);

		int cnt = 0;
		for (int i = 0; i < 3; i++)
		{
			cin >> v[i];

			if (v[i] == 0)
			{
				cnt++;
			}
		}

		if (cnt >= 3) break;

		sort(v.begin(), v.end());

		if (v[2] >= (v[0] + v[1]))
		{
			cout << "Invalid\n";
			continue;
		}

		if (v[0] == v[1] && v[1] == v[2])
		{
			cout << "Equilateral\n";
		}
		else if (v[0] == v[1] || v[1] == v[2] || v[0] == v[2])
		{
			cout << "Isosceles\n";
		}
		else
		{
			cout << "Scalene\n";
		}
		
	}
}
