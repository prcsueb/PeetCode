class Solution {
public:
    int calculate(string s) {
        long long slen = s.length();
        char sign = '+';
        stack<long long> stk;
        for(int i=0;i<slen;i++) {
            //if digit else sign no other option
            if(s[i] == ' ') {
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9') {
                long long val = 0;
                while(i < slen && s[i] >= '0' && s[i] <= '9') {
                    val = val*10+s[i]-'0';
                    i++;
                }
                i--;
                if(sign == '*') {
                    long long top = stk.top();
                    stk.pop();
                    long long newVal = val * top;
                    stk.push(newVal);
                } else if(sign == '/') {
                    long long top = stk.top();
                    stk.pop();
                    long long newVal = top / val;
                    stk.push(newVal);
                } else {
                    if(sign == '+') {
                        stk.push(val);
                    } else {
                        stk.push(-val);
                    }
                }
            } else {
                sign = s[i];
            }
        }
        
        long long ans = 0;
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};