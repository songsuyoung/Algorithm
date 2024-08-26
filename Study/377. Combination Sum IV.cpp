class Solution {
public:

    int recursive(vector<int> &nums,vector<int> &dp,int sum, int target)
    {
        if(sum == target) return 1;
        if(sum > target) return 0;

        if(dp[sum]!=-1) return dp[sum];
        dp[sum]=0;
        
        for(int i=0;i<nums.size();i++)
        {
            //선택한다.
            dp[sum]+=recursive(nums,dp, sum + nums[i], target);
            //선택안한다.
        }

        return dp[sum];
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> dp(target+1,-1);
        sort(nums.begin(),nums.end());

        return recursive(nums,dp,0,target);
    }
};