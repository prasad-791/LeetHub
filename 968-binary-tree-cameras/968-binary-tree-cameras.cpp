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
    int cam=0;
    // 3 cases:
    //      1) the node is a camera - return 0
    //      2) the node is not a camera and is covered by its left or right child - return 1
    //      3) the node is not a camera and is not covered by its left or right child - return -1
    //      -1 will indicate that the left or right child needs a camera, so the parent has to become a
    //      camera
    //      for root == null, we will return 1 i.e. it is covered 
    
    int help(TreeNode* root){
        if(!root) return 1;
        int lc = help(root->left);
        int rc = help(root->right);
        
        if(lc == -1 || rc == -1){
            // left or right child is not covered i.e. cover it
            cam++;
            return 0;
        }
        if(lc == 0 || rc == 0){
            // left or right child is a camera i.e. this root is covered
            return 1;
        }
        // left and right both are covered i.e. this root needs to be covered 
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(help(root)==-1) cam++;
        return cam;
    }
};