#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int CalBudget(vector<int> budget,int limit)
{
	int sum = 0;
	for (int i = 0; i < budget.size(); i++)
	{
		if (budget[i] >= limit)
			sum += limit;
		else
			sum += budget[i];
	}

	return sum;
}
int main()
{
	int N;

	cin >> N;

	vector<int> budget;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		budget.push_back(tmp);
	}

	int totalLimit;
	cin >> totalLimit;
	int resultLimit = 0;
	sort(budget.begin(), budget.end());
	int left = 1, right = budget[N - 1];
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (CalBudget(budget, mid) > totalLimit) {
			right = mid - 1;
		}
		else {
			resultLimit = mid;
			left = mid + 1;
		}
	}

	cout << resultLimit << '\n';
}