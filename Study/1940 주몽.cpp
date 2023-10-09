#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, M;

	vector<int> material;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		material.push_back(tmp);
	}

	sort(material.begin(), material.end());
	int left = 0;
	int right = material.size() - 1;

	int cnt = 0;
	while (left < right) {

		long long sum = material[left] + material[right];
		
		cout << material[left] << ' ' << material[right] << '\n';
		if (sum == M) {
			cnt++;
			right--;
			left++;
		}
		else if(sum<M){
			left++;
		}
		else if (sum > M) {
			right--;
		}
	}

	cout << cnt << '\n';

}