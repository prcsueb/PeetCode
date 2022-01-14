class Solution {
public:
    int myAtoi(string s) {
        int slen = s.length();
        long long i=0;
        while(i<slen && s[i]==' ') {
            i++;
        }
        int sign = 1;
        if(i < slen && s[i]=='-') {
            sign=-1;
            i++;
        } else if(i < slen && s[i]=='+') {
            sign=1;
            i++;
        }
        
        while(i<slen && s[i]=='0') {
            i++;
        }
        if(i==slen) {
            return 0;
        }
        int result=0;
        while(i<slen && s[i]>='0' && s[i]<='9') {
            int digit = s[i] - '0';

          if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)){
              return sign==-1 ? INT_MIN : INT_MAX;
          }

          result = (result * 10) + digit;

          ++i;
        }
        if(sign == -1) {
            result=-result;
        }
        
        return result;
    }
};
