class Solution {
public:

    void inOrder(TreeNode *root,vector<int> &v)
    {
        if(root==nullptr){
            return ;
        }

        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inOrder(root,v);
        return v;   
    }
};