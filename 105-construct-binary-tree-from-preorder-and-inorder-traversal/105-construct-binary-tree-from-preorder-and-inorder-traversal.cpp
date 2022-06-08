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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 && inorder.size()==0){
            return NULL;
        }
        vector<int> lpre, lin, rpre, rin;
        int root = preorder[0], c=0,i=0;
        // left subtree inorder
        while(i<inorder.size() && inorder[i]!=root){
            lin.push_back(inorder[i]);
            i++;
        }
        i++;
        // right subtree inorder
        while(i<inorder.size()){
            rin.push_back(inorder[i]);
            i++;
        }
        int n=lin.size();
        i=1;
        // left subtree preorder
        while(n--){
            lpre.push_back(preorder[i]);
            i++;
        }
        // right subtree preorder
        while(i<preorder.size()){
            rpre.push_back(preorder[i]);
            i++;
        }
        TreeNode* node = new TreeNode(root);
        node->left = buildTree(lpre,lin);
        node->right = buildTree(rpre,rin);
        return node;
    }
};