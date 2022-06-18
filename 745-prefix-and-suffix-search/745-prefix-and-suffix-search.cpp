// class Tries{
// public:
//     Tries *t[26];
//     vector<int> index;
    
//     Tries(){
//         memset(t,0,sizeof(t));
//         index = vector<int>();
//     }
    
//     void insert(string word,int i){
//         Tries *root = this;
//         for(auto& ch:word){
//             if(root->t[ch-'a']==NULL){
//                 root->t[ch-'a'] = new Tries();
//             }
//             root = root->t[ch-'a'];
//             root->index.push_back(i);
//         }
//     }
//     vector<int> startsWith(string word){
//         Tries *root = this;
//         for(auto& ch:word){
//             if(root->t[ch-'a']==NULL){
//                 return vector<int>();
//             }
//             root = root->t[ch-'a'];
//         }
//         return root->index;
//     }
// };

// class WordFilter {
// public:
//     Tries prefix;
//     Tries suffix;
//     WordFilter(vector<string>& words) {
//         for(int i=0;i<words.size();i++){
//             prefix.insert(words[i],i);
//             reverse(words[i].begin(),words[i].end());
//             suffix.insert(words[i],i);
//         }
//     }
    
//     int f(string pre, string suff) {
//         vector<int> preind = prefix.startsWith(pre);
//         reverse(suff.begin(),suff.end());
//         vector<int> suffind = suffix.startsWith(suff);
        
//         int i=preind.size()-1, j=suffind.size()-1;
//         while(i>=0 && j>=0){
//             if(preind[i]==suffind[j]){
//                 return preind[i];
//             }else if(preind[i] > suffind[j]){
//                 i--;
//             }else{
//                 j--;
//             }
//         }
//         return -1;
//     }
// };

class trie {
    trie* ch[27];
    int weight;
public:
    trie() {
        memset(ch, 0, sizeof(ch));
        weight = 0;
    }
    void insert(string str, int weight) {
        trie* node = this;
        for (char c: str) {
            if (node->ch[c - 'a'] == NULL)
                node->ch[c - 'a'] = new trie();
            node = node->ch[c - 'a'];
            node->weight = weight;
        }
    }
    int startsWith(string str) {
        trie* node = this;
        for (char c: str) {
            if (node->ch[c - 'a'] == NULL)
                return -1;
            node = node->ch[c - 'a'];
        }
        return node->weight;
    }
};
class WordFilter {
public:
    trie root;
    WordFilter(vector<string>& words) {
        int idx = 0;
        for (string word: words) {
            root.insert(word, idx);
            string tmp = "{" + word;
            for (int i = word.length() - 1; i >= 0; i--) {
                string newword = word[i] + tmp;
                tmp = newword;
                root.insert(newword, idx);
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        string word = suffix + "{" + prefix;
        return root.startsWith(word);
    }
};



/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */