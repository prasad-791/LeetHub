class FreqStack {
public:
    map<int,int> freqMap;
    map<int,stack<int>> setMap;
    int maxf=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freqMap[val]++;
        maxf = max(maxf,freqMap[val]);
        setMap[freqMap[val]].push(val);
    }
    
    int pop() {
        int x = setMap[maxf].top();
        setMap[maxf].pop();
        freqMap[x]--;
        if(setMap[maxf].size()==0){
            maxf--;
        }
        return x;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */