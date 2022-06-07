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
    vector<vector<int>> paths;
    void help(TreeNode* root, int targetSum,int sum,vector<int> a){
        if(!root) return;
        if(!root->left && !root->right){
            if(root->val+sum == targetSum){
                a.push_back(root->val);
                paths.push_back(a);
            }
            return ;
        }
        a.push_back(root->val);
        help(root->left,targetSum,sum+root->val,a);
        help(root->right,targetSum,sum+root->val,a);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        help(root,targetSum,0,{});
        return paths;
    }
};