class Solution {
public:
    class Node{
        public:
        Node* one;
        Node* zero;
    };
    class Trie{
        public:
        Node *node;
        Trie(){
            node = new Node();
        }
        void insert(int num){
            Node* root = node;
            for(int i=31;i>=0;i--){
                int bit = 0;
                if(1<<i & num){
                      bit = 1;
                }
                if(bit==1){
                    if(root->one == NULL){
                        root->one = new Node();
                    }
                    root = root->one;
                }else{
                    if(root->zero == NULL){
                        root->zero = new Node();
                    }
                    root = root->zero;
                }
            }
        }
        int getMaxXORForCurrEle(int x){
            Node* root = node;
            int num = 0;
            for(int i=31;i>=0;i--){
                int bit = 0;
                if(1<<i & x){
                    bit = 1;
                }
                if(bit==1){
                    if(root->zero){
                        root = root->zero;
                        num += (1<<i);
                    }else{
                        root = root->one;
                    }
                }else{
                    if(root->one){
                        root = root->one;
                        num += (1<<i);
                    }else{
                        root = root->zero;
                    }
                }
            }
            return num;
        }
    };
    
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        for(auto& x:nums){
            root->insert(x);
        }
        int ans = INT_MIN;
        for(auto& x:nums){
            ans = max(ans,root->getMaxXORForCurrEle(x));
        }
        return ans;
    }
};