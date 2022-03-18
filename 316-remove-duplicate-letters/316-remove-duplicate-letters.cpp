class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> a(26,0);
        map<char,int> mp;
        for(auto& c:s){
            a[c-'a']++;
            mp[c]=0;
        }
        for(auto& c:s){
            a[c-'a']--;
            if(mp[c]==1){
                continue;
            }
            if(st.empty()){
                st.push(c);
                mp[c]=1;
            }else{
                if(st.top()<c){
                    st.push(c);
                    mp[c] = 1;
                }else if(st.top()>c){
                    if(a[st.top()-'a']==0){
                        st.push(c);
                        mp[c] = 1;
                    }else{
                        while(!st.empty() && a[st.top()-'a']>0 && st.top()>c){
                            mp[st.top()] = 0;
                            st.pop();
                        }
                        st.push(c);
                        mp[c] = 1;
                    }
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};