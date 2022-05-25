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
    NestedIterator(vector<NestedInteger> &nestedList) {
        begin.push(nestedList.begin());
        end.push(nestedList.end());
    }
    
    int next() {
        hasNext();
        return begin.top()++->getInteger();
    }
    
    bool hasNext() {
        while(!begin.empty()) {
            if(begin.top() == end.top()) {
                begin.pop();
                end.pop();
            } else {
                vector<NestedInteger> :: iterator x = begin.top();
                if(x->isInteger()) {
                    return true;
                } else {
                    begin.top()++;
                    begin.push(x->getList().begin());
                    end.push(x->getList().end());
                }
            }
        }
        return false;
    }
    private:
        stack<vector<NestedInteger> :: iterator> begin, end;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */