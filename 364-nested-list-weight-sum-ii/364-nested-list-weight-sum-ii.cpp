/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int getMaxepth(vector<NestedInteger>& nestedList) {
        int depth = 1;
        for(NestedInteger x : nestedList) {
            if(!x.isInteger()) {
                depth = max(depth, 1 + getMaxepth(x.getList()));
            }
        }
        return depth;
    }
    int getWeightedSum(vector<NestedInteger>& nestedList, int level, int maxDepth) {
        int sum = 0;
        for(NestedInteger x : nestedList) {
            if(!x.isInteger()) {
                sum += getWeightedSum(x.getList(), level+1, maxDepth);
            } else {
                sum += x.getInteger() * (maxDepth - level + 1);
            }
        }
        return sum;
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = getMaxepth(nestedList);
        int sum = getWeightedSum(nestedList, 1, maxDepth);
        return sum;
    }
};