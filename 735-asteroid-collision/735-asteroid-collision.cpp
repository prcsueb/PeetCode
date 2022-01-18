class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> stk;
        
        for(int i=0;i<a.size();i++) {
            //insert all +ve
            if(a[i] > 0) {
                stk.push(a[i]);
            } else {
                while(!stk.empty() && stk.top()>0 && a[i]<0 && stk.top() < abs(a[i])) {
                    stk.pop();
                }
                if(!stk.empty() && stk.top() == -a[i]) {
                    stk.pop();
                } else if(!stk.empty() && stk.top() > -a[i]) {
                    
                } else {
                    stk.push(a[i]); //stk.top ni dir ma a[i] hoi k pachi stk empty hoi banne case ma 
                    //directly insert karo
                }
            }
        }
        vector<int> ans(stk.size());
        int size = stk.size()-1;
        while(!stk.empty()) {
            ans[size] = stk.top();
            size--;
            stk.pop();
        }
        return ans;
    }
};