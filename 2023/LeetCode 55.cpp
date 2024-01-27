class Solution {
public:

    //bfs?
    int bfs(vector<int> &nums,int start)
    {
        queue<pair<int,int>> q;
        vector<bool> isVisited(nums.size(),false);
        q.push(make_pair(start,0));

        while(!q.empty())
        {
            pair<int,int> cur=q.front();
            q.pop();

            if(cur.first>=(nums.size()-1)) return cur.second;
            if(isVisited[cur.first]) continue;
            isVisited[cur.first]=true;

            for(int i=nums[cur.first];i>=1;i--)
            {
                if(cur.first+i>=nums.size()||isVisited[cur.first+i]) continue;
                q.push(make_pair(cur.first+i,cur.second+1));
            }
        }

        return -1;
    }
    bool canJump(vector<int>& nums) {
        return bfs(nums,0)!=-1;
    }
};