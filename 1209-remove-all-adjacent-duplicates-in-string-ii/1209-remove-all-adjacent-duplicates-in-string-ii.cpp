class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push(make_pair(s[0],1));
        for(int i=1;i<s.length();i++){
            int count = 1;
            if(!st.empty() && s[i]==st.top().first){
                count = st.top().second+1;
                st.pop();
            }
            st.push(make_pair(s[i],count));   
            if(st.top().second == k){
                st.pop();
            }
            // cout<<i<<" "<<st.size()<<"\n";
        }
        s = "";
        while(!st.empty()){
            int count = st.top().second;
            string temp = "";
            while(count--){
                temp += st.top().first;
            }
            s = temp + s;
            st.pop();
        }
        
        return s;
    }
};