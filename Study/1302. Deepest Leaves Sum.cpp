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

    pair<int,int> dfs(TreeNode *node)
    {
        if(node->left == nullptr && node->right == nullptr) 
        {
            return {1,node->val}; //level - value 전달
        }
        pair<int,int> left, right;

        if(node->left)
        {
            left = dfs(node->left);
        }   

        if(node->right)
        {
            right = dfs(node->right);
        }     

        if(left.first < right.first)
        {
            return {right.first + 1, right.second};
        }
        else if(right.first <left.first)
        {
            return {left.first + 1, left.second};
        }

        return {right.first + 1, left.second + right.second};
    }
    int deepestLeavesSum(TreeNode* root) {
        
        int answer=0;

        pair<int,int> res = dfs(root);

        return res.second;
    }
};