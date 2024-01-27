#include <bits/stdc++.h>
using namespace std;

struct Link
{
	int computer1;
	int computer2;
	int cost;
};

int parent[1005];
int Find(int a)
{
	if (a == parent[a]) return parent[a];
	return parent[a] = Find(parent[a]);
}
void Union(int a, int b)
{
	if (a != b)
	{
		a = Find(a);
		b = Find(b);

		parent[a] = b;
	}
}
bool Compare(Link& a, Link& b)
{
	return a.cost < b.cost;
}

int main()
{
	int N;
	cin >> N;

	int E;
	cin >> E;

	vector<Link> linking(E);
	for (int i = 0; i < E; i++)
	{
		cin >> linking[i].computer1 >> linking[i].computer2 >> linking[i].cost;
	}

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	sort(linking.begin(), linking.end(), Compare);

	int cost=0;
	for (int i = 0; i < linking.size(); i++)
	{
		if (Find(linking[i].computer1) != Find(linking[i].computer2))
		{
			Union(linking[i].computer1, linking[i].computer2);
			cost += linking[i].cost;
		}
	}

	cout << cost << '\n';
}