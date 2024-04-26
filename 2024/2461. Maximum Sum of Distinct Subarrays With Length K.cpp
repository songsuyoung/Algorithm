class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        vector<int> arr(100'001,0);
        set<int> checkNum;
        long long maxVal=0,sum=0;
        //1 5 5
        //11 -> maxVal
        bool isRepeated=false;
        for(int i=0;i<k;i++)
        {
            arr[nums[i]]++;
            sum+=nums[i];
            checkNum.insert(nums[i]);
        }
        if(checkNum.size()==k)
        {
            maxVal = max(sum,maxVal);
        }
        int left=0;
        for(int i=k;i<nums.size();i++)
        {
            if(arr[nums[left]]==1)
            {
                checkNum.erase(nums[left]);
            }
            arr[nums[left]]--;
            sum-=nums[left++];
            arr[nums[i]]++;
            sum+=nums[i];
            checkNum.insert(nums[i]);

            if(checkNum.size()==k)
            {
                maxVal = max(sum,maxVal);
            }
        }

        return maxVal;
    }
};