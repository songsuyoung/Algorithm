class Solution {
public:
    
    pair<int,int> LIS(vector<int> &nums, vector<int> &dp,int idx)
    {
        if(idx == nums.size()-1)
        {
            dp[idx]=1;
            return make_pair(idx,dp[idx]);
        }

        pair<int,int> res = LIS(nums,dp, idx+1);

        if(nums[res.first]>nums[idx])
        {
            dp[idx] = res.second + 1;

            return make_pair(idx, dp[idx]);
        }

        for(int i=idx+1;i<nums.size();i++)
        {
            if(nums[idx]<nums[i]&&dp[idx]<=dp[i])
            {
                dp[idx]=dp[i] + 1;
            }
        }

        return dp[idx]>res.second ? make_pair(idx, dp[idx]) : res ;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        return LIS(nums, dp, 0).second;
    }
};