#define ll long long
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while(target>startValue){
            target = target%2==0 ? target/2 : target+1;
            count++;
        }
        if(target < startValue){
            count += (startValue-target);
        }
        return count;
    }
};