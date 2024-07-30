#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	
	int N;
	cin >> N; //최대 3,000,000

	unordered_map<int,int> v;

	for (int i = 0; i < N; i++)
	{
		string op;
		
		cin >> op;

		if (op == "empty")
		{
			v.clear();
		}
		else if (op == "all")
		{
			for (int j = 1; j <= 20; j++)
			{
				v[j] = 1;
			}
		}
		else
		{

			int num;
			cin >> num;

			if (op == "add")
			{
				v[num] = 1;
			}
			else if (op == "remove")
			{
				v[num] = 0;
			}
			else if (op == "check")
			{
				cout << v[num] << '\n';
			}
			else if (op == "toggle")
			{
				v[num] = !v[num];
			}
		}
	}

}