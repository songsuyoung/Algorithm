#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recursive(vector<int>& arr,vector<int> &nums, int M,int idx)
{
    if (nums.size() == M)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (find(nums.begin(), nums.end(), arr[i]) != nums.end()) continue;
        nums.push_back(arr[i]);
        recursive(arr, nums,M, i+1);
        nums.pop_back();
    }
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N, 0);
    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<int> nums;
    recursive(arr,nums,M,0);
}