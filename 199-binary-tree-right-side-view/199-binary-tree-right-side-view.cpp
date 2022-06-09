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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> st;
        st.push(root);
        ans.push_back(root->val);
        while(!st.empty()){
            int rv = -1000;
            queue<TreeNode*> temp;
            while(!st.empty()){
                TreeNode* node = st.front();
                if(node->left){
                    temp.push(node->left);
                    rv = node->left->val;
                }
                if(node->right){
                    temp.push(node->right);
                    rv = node->right->val;
                }
                st.pop();
            }
            if(temp.size()>0){
                ans.push_back(rv);
            }
            st = temp;
        }
        
        return ans;
    }
};