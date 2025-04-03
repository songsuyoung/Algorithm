#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while (true)
	{
		vector<int> line(3,0);

		cin >> line[0] >> line[1] >> line[2];

		if (line[0] == 0 && line[1] == 0 && line[2] == 0) break;

		sort(line.begin(), line.end());

		if (line[0] + line[1] <= line[2])
		{
			cout << "Invalid\n";
		}
		else if (line[0] == line[1] && line[1] == line[2])
		{
			cout << "Equilateral\n";
		}
		else if (line[0] == line[1] || line[1] == line[2])
		{
			cout << "Isosceles\n";
		}
		else
		{
			cout << "Scalene\n";
		}
		
	}
	return 0;
}