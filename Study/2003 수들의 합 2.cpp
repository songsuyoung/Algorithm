#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int N, M;
    cin >> N >> M;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int left = 0;
    int right = 0;
    int cnt = 0,sum=v[right];
    while (left<=right && right< N ) {
        if (sum < M) {
            sum += v[++right];
        }
        else if (sum > M) {
            sum -= v[left++];
            
            if(left>right) {
                right = left;
                sum = v[left];
            }
        }
        else {
            cnt++;
            sum += v[++right];
        }

    }

    cout << cnt << '\n';
    return 0;
}