#include <iostream>
#include <vector>
using namespace std;

int main() 
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;

        vector<int> coins(N, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> coins[i];
        }

        int dest;
        cin >> dest;

        vector<int> dp(dest + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = coins[i]; j <= dest; j++)
            {
                dp[j] = dp[j - coins[i]] + dp[j];
            }
        }

        cout << dp[dest] << '\n';
    }
    return 0;
}
