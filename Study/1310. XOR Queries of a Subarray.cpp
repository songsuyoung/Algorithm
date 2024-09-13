class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> answer;
        
        for(int i=1;i<arr.size();i++)
        {
            arr[i]^=arr[i-1];
        }
        
        for(int i=0;i<queries.size();i++)
        {
            int idx1 = queries[i][0];
            int idx2 = queries[i][1];
        
            if(idx1<=0)
            {
                answer.push_back(arr[idx2]);
            }
            else
            {
                answer.push_back(arr[idx1-1]^arr[idx2]);
            }
        }
        return answer;
    }

};