class Solution {
public:
    int calculate(string s) {
        long long sum = 0;
        long long sign = 1;
        
        stack<long long> stk;
        for(long long i=0;i<s.length();i++) {
            char c = s[i];
            //if space then continue
            if(c == ' ') {
                continue;
            }
            //digit
            if(c >= '0' && c <= '9') {
                long long val = 0;
                while(i < s.length() && (s[i] >= '0' && s[i] <= '9')) {
                    val = val * 10 + (s[i]-'0'); //val = 1*10 + 2 = 12 123
                    i++;
                }
                val = val * sign;
                sum += val;
                sign = 1;
                i--;
            } else if(c == '(') {
                // (
                stk.push(sum);
                stk.push(sign);
                sum = 0;
                sign = 1;
            } else if(c == ')') {
                //)
                sum *= stk.top(); stk.pop();
                sum += stk.top(); stk.pop();
            } else if(c == '-') {
                sign *= -1;
            }
        }
        cout <<sum << endl;
        
        return sum;
    }
};