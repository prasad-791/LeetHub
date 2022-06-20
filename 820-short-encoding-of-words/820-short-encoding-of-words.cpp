class Solution {
public:
    static bool cmp(string& a, string& b){
        if(a.length()==b.length()){
            return b>a;
        }
        return a.length()>=b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        string s="";
        for(int i=0;i<words.size();i++){
            int pos = s.find(words[i]+'#');
            if(pos==-1){
                s += words[i]+'#';
            }
        }
        return s.length();
    }
};
