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
    int ans = INT_MIN;
    int help(TreeNode* root){
        if(!root) return 0;
        int lv = max(help(root->left),0);
        int rv = max(help(root->right),0);
        ans = max(ans,root->val+lv+rv);
        return root->val + max(lv,rv);
    }
    
    int maxPathSum(TreeNode* root,int sum=0) {
        help(root);
        return ans;
    }
};