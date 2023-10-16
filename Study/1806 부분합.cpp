#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main() {

	int N,M;

	cin >> N>>M;

	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	v.push_back(0);
	int left = 0, right = 0;
	int sum = v[right];
	int subtotalCnt = INT_MAX;

	while (left <= right&&right < N) {

		if (left > N)
			break;
		if (sum < M) {
			sum += v[++right];
		}
		else if (sum >= M) {
			subtotalCnt = min(subtotalCnt, abs(left - right) + 1);
			sum -= v[left++];

			if (left > right) {
				right = left;
				sum = v[left];
			}
		}
	}

	if (subtotalCnt == INT_MAX)
		subtotalCnt = 0;

	cout << subtotalCnt << '\n';
}