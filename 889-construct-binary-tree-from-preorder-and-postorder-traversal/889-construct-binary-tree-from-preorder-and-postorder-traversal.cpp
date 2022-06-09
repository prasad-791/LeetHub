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
    TreeNode* help(vector<int>& pre, vector<int>& po, int lppr, int rppr, int lpo, int rpo){
        if(lppr > rppr || lpo > rpo){
            return NULL;
        }
        int root = pre[lppr];
        TreeNode* node = new TreeNode(root);
        if(lppr == rppr && lpo == rpo){
            return node;
        }
        int f = mp[pre[lppr+1]];
        int c = f - lpo + 1;
        node->left = help(pre,po,lppr+1,lppr+c,lpo,f);
        node->right = help(pre,po,lppr+c+1,rppr,f+1,rpo-1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]] = i;
        }
        return help(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1);
    }
};