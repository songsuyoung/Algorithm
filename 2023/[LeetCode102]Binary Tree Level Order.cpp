/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        queue<pair<int,TreeNode*>> q;
        q.push(make_pair(0,root)); 
        vector<int> buffer;
        int curlevel=0;
        while(!q.empty())
        {
            int level = q.front().first;
            TreeNode * tmp =q.front().second;
            q.pop();
            if(tmp==nullptr)
            {
                continue;
            }
            if(level != curlevel)
            {
                result.push_back(buffer);
                buffer.clear();
                curlevel=level;
            }
            //root이면
            buffer.push_back(tmp->val);
            q.push(make_pair(level+1,tmp->left));
            q.push(make_pair(level+1,tmp->right));
        }

        if(!buffer.empty())
        {
            result.push_back(buffer);
        }
        return result;
    }
};