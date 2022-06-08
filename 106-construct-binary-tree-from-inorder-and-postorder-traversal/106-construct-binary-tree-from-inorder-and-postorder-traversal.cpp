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
    map<int,int> mp;
    TreeNode* help(vector<int>& in,vector<int>& po,int lpi, int rpi, int lpp, int rpp){
        if(lpi > rpi || lpp > rpp){
            return NULL;
        }
        int root = po[rpp];
        TreeNode* node = new TreeNode(root);
        int f = mp[root],c=0;
        c = rpi-f;
        node->right = help(in,po,f+1,rpi,rpp-c,rpp-1);
        node->left = help(in,po,lpi,f-1,lpp,rpp-c-1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }    
        return help(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};