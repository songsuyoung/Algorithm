class Solution {
public:

    int cnt(vector<int> &nums,int target,int sum,int idx)
    {
        if(idx>=nums.size())
        {
            if(sum == target)
            {
                return 1;
            }
            return 0;
        }

        //+
        int plus = cnt(nums,target,sum+nums[idx],idx+1);    
        //-
        int minus = cnt(nums,target,sum-nums[idx],idx+1);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        return cnt(nums,target,0,0);
    }
};