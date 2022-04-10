class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        for(auto& s:ops){
            if(s=="C"){
                ans.pop_back();
            }else if(s=="D"){
                ans.push_back(ans[ans.size()-1]*2);
            }else if(s=="+"){
                ans.push_back(ans[ans.size()-1]+ans[ans.size()-2]);
            }else{
                int num1 = 0;
                bool isneg = s[0]=='-';
                int i = isneg ? 1 :  0;
                for(;i<s.length();i++){
                    num1 = num1*10 + (s[i]-48);
                }
                num1 = isneg ? (-1)*num1 : num1;
                ans.push_back(num1);
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};