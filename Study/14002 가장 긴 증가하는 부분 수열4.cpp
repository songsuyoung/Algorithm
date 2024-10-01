#include <iostream>
#include <vector>

using namespace std;

pair<int, int> recursive(vector<int>& arr, vector<int>& dp, vector<int> &res, int idx)
{
    if (idx >= arr.size() - 1)
    {
        dp[idx] = 1;
        res[idx] = -1; //여기가 마지막
        return {idx,dp[idx]};
    }

    pair<int, int> pre = recursive(arr, dp,res, idx + 1);

    if (arr[pre.first] > arr[idx])
    {
        dp[idx] = pre.second + 1;
        res[idx] = pre.first;
        return { idx, dp[idx] };
    }

    dp[idx] = 1;
    for (int i = idx; i < arr.size(); i++)
    {
        if (arr[idx] < arr[i] && dp[idx] <= dp[i])
        {
            dp[idx] = dp[i] + 1;
            res[idx] = i;
        }
    }

    return dp[idx] > pre.second ? make_pair(idx, dp[idx]) : pre;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> dp(N, 0);
    vector<int> arr(N, 0);
    vector<int> res(N, -1);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    pair<int, int> output = recursive(arr, dp, res, 0);
    cout << output.second << '\n';

    int idx = output.first;
    while (idx != -1)
    {
        cout << arr[idx] << ' ';
        idx = res[idx];
    }
    cout << '\n';
}