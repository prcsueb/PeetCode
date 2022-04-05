class Solution {
    double helper(double x, int n) {
        if(n == 0) {
            return 1.0;
        } 
        double halfAns = helper(x, n/2);
        double fullAns = halfAns * halfAns;
        if(n % 2 != 0) {
            fullAns = x * fullAns;
        }
        return fullAns;
    }
    public double myPow(double x, int n) {
        if(n == 0) {
            return 1.0;
        }
        double ans = helper(x, n);
        if(n < 0) {
            return 1/ans;
        }
        return ans;
    }
}