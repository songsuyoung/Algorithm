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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> v;
        queue<int> q;
        stack<TreeNode *> st;

        st.push(root);
        q.push(1);


        stack<TreeNode *> st1;
        vector<int> tmp;
                
        int prelevel=1;

        while(!q.empty())
        {
            int level = q.front();
            
            if(st.empty())
            {
                vector<TreeNode *> vtmp;
                while(!st1.empty())
                {
                    vtmp.push_back(st1.top());
                    st1.pop();
                }

                for(int i=vtmp.size()-1; i>=0 ;i--)
                {
                    st.push(vtmp[i]);
                }
                
                v.push_back(tmp);
                tmp.clear();
            }

            TreeNode *node = st.top();

            st.pop();
            q.pop();

            if(node!=nullptr)
            {
                tmp.push_back(node->val);
                if(level % 2 == 0)
                {
                    //왼->오
                    st1.push(node->right);
                    st1.push(node->left);
                }   
                else
                {   
                    //오->왼
                    st1.push(node->left);
                    st1.push(node->right);
                }

                q.push(level+1);
                q.push(level+1);
                prelevel = level;
            }
        }
        return v;
    }
};