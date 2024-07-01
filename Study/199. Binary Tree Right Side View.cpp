class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        vector<pair<int,int>> v;
        while(!q.empty())
        {
            TreeNode *cur = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(cur == nullptr) continue;
            v.push_back({cur->val,cnt});
            q.push({cur->left,cnt+1});
            q.push({cur->right,cnt+1});
        }

        map<int,int> visited;
        vector<int> res;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(visited[v[i].second] == false)
            {
                res.push_back(v[i].first);
                visited[v[i].second] = true;
            }
        }

        reverse(res.begin(),res.end());

        return res;
    }

};