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
    int sumNumbers(TreeNode* root,int num=0) {
        if(!root) return 0;
        if(!root->left && !root->right){
            num = num*10 + root->val;
            return num;
        }
        int ln = sumNumbers(root->left,num*10+root->val);
        int rn = sumNumbers(root->right,num*10+root->val);
        return ln+rn;
    }
};