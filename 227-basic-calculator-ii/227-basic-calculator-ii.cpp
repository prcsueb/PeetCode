class Solution {
public:
    int calculate(string s) {
        stack<long long> stk;
        char sign = '+';
        
        long long slen = s.length();
        for(long long i=0;i<slen;i++) {
            //1.get value
            if(s[i] >= '0' && s[i] <= '9') {
                //get whole value until found something other than digit
                long long val = 0;
                while(i < slen && s[i] >= '0' && s[i] <= '9') {
                    val = val * 10 + s[i] - '0';
                    i++;
                }
                
                --i;
                if(sign == '+') {
                    stk.push(val);
                } else if(sign == '-') {
                    stk.push(-val);
                } else if(sign == '*') {
                    long long x = stk.top();
                    stk.pop();
                    stk.push(x * val);
                } else if(sign == '/') {
                    int x = stk.top();
                    stk.pop();
                    stk.push(x / val);
                }
            } else if(s[i] == ' ') {
                continue;
            } else {
                //2.get sign
                sign = s[i];
            }   
        }
        
        long long sum = 0;
        while(!stk.empty()) {
            cout << stk.top() << " , ";
            sum += stk.top(); stk.pop();
        }
        
        return sum;
    }
};