/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> a;
    int ind=0;
    void solve(NestedInteger li){
        if(li.isInteger()){
            a.push_back(li.getInteger());
            return ;
        }
        vector<NestedInteger> l = li.getList();
        for(int i=0;i<l.size();i++){
            solve(l[i]);
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=0;i<nestedList.size();i++){
            solve(nestedList[i]);
        }
    }
    
    int next() {
        return a[ind++];
    }
    
    bool hasNext() {
        return ind < a.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */