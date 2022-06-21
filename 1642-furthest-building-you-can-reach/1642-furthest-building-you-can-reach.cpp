class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int i=0;
        while(i<h.size()-1){
            if(h[i]<h[i+1]){
                int diff = h[i+1] - h[i];
                minHeap.push(diff);
                if(minHeap.size()>ladders){
                    int ele = minHeap.top();
                    minHeap.pop();
                    if(ele > bricks){
                        break;
                    }
                    bricks -= ele;
                }
            }
            i++;
        }
        return i;
    }
};