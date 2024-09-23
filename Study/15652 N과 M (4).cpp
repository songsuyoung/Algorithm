#include <iostream>
#include <vector>

using namespace std;

void recursive(int N, int M, vector<int>& nums,int idx)
{
    if (nums.size() == M)
    {
        for (int i = 0; i <M;i++)
        {
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = idx; i <= N; i++)
    {
        nums.push_back(i);
        recursive(N, M, nums,i);
        nums.pop_back();
    }
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<int> nums;
    recursive(N, M, nums,1);
}