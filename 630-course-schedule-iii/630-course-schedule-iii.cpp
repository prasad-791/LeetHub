class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<vector<int>> maxHeap;
        sort(courses.begin(),courses.end(),cmp);
        int ans = 0;
        int currans = 0;
        int currT = 0;
        for(auto& c:courses){
            // cout<<c[0]<<" "<<c[1]<<endl;
            if(currT+c[0]>c[1] && maxHeap.size()>0){
                vector<int> temp = maxHeap.top();
                if(temp[0]>c[0]){
                    currT -= temp[0];
                    maxHeap.pop();
                    currans--;
                }
            }
            if(currT+c[0]<=c[1]){
                currans++;
                currT += c[0];
                maxHeap.push(c);
            }
            ans = max(ans,currans);
        }
        return ans;
    }
};