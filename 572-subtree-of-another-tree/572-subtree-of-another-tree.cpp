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
    bool checkTree(TreeNode* root,TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if((!root && subRoot) || (!subRoot && root)) return false;
        if(root->val!=subRoot->val){
            return false;
        }
        return checkTree(root->left,subRoot->left) && checkTree(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        bool ans  = false;
        if(root->val == subRoot->val){
            ans = checkTree(root,subRoot);
        }
        return ans || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};