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
    TreeNode* insertIntoBSTRecursive(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        if(val > root->val){
            root->right = insertIntoBST(root->right,val);
            return root;
        }
        root->left = insertIntoBST(root->left,val);
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root, *prev = NULL;
        while(temp!=NULL){
            prev = temp;
            if(temp->val < val){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        TreeNode* t = new TreeNode(val);
        if(!prev) return t;
        if(prev->val > val){
            prev->left = t;
        }else{
            prev->right = t;
        }
        return root;
    }
};