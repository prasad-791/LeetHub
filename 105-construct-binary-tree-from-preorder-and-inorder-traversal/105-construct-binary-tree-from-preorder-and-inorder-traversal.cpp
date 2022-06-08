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
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     if(preorder.size()==0 && inorder.size()==0){
    //         return NULL;
    //     }
    //     vector<int> lpre, lin, rpre, rin;
    //     int root = preorder[0], c=0,i=0;
    //     // left subtree inorder
    //     while(i<inorder.size() && inorder[i]!=root){
    //         lin.push_back(inorder[i]);
    //         i++;
    //     }
    //     i++;
    //     // right subtree inorder
    //     while(i<inorder.size()){
    //         rin.push_back(inorder[i]);
    //         i++;
    //     }
    //     int n=lin.size();
    //     i=1;
    //     // left subtree preorder
    //     while(n--){
    //         lpre.push_back(preorder[i]);
    //         i++;
    //     }
    //     // right subtree preorder
    //     while(i<preorder.size()){
    //         rpre.push_back(preorder[i]);
    //         i++;
    //     }
    //     TreeNode* node = new TreeNode(root);
    //     node->left = buildTree(lpre,lin);
    //     node->right = buildTree(rpre,rin);
    //     return node;
    // }
    
    map<int,int> pmap;
    map<int,int> imap;
    
    TreeNode* help(vector<int>& pre,vector<int> in,int lpp,int rpp, int lpi, int rpi){
        if(lpp > rpp || lpi > rpi){
            return NULL;
        }
        int root = pre[lpp];
        int f = imap[root];
        TreeNode* node = new TreeNode(root);
        int count = f-lpi;
        node->left = help(pre,in,lpp+1,lpp+count,lpi,f-1);
        node->right = help(pre,in,lpp+count+1,rpp,f+1,rpi);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++){
            pmap[preorder[i]] = i;
        }
        for(int i=0;i<preorder.size();i++){
            imap[inorder[i]] = i;
        }
        return help(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};