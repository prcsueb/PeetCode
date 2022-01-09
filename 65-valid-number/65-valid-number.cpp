class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool e = false;
        int plmi = 0;
        int slen = s.length();
        
        //digit, dot, e, +-
        
        for(int i=0;i<slen;i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                digit=true;
            } else if(s[i]=='.') {
                //1. .can't occur after e
                //2.only one dot allowed
                //3.there should be atlease on digit till the end of the string
                if(dot || e) {
                    return false;
                }
                if(i == slen-1 && !digit) {
                    return false;
                }
                
                dot = true;
            } else if(s[i] == 'e' || s[i] == 'E') {
                //1.e can't be starting point
                //2.only single e is allowed
                //3.e should occur after one digit
                // .e e33
                if(e || i == 0) {
                    cout << "aa";
                    return false;
                }
                if(i == slen-1 || !digit) {
                    cout << "a";
                    return false;
                }
                e = true;
            } else if(s[i] == '+' || s[i] == '-') {
                //1.there are only one + or - allowed
                //2.can't be at the end
                //3.if occurs in the middle then before that must an e or E
                if(plmi > 1 || i == slen-1) {
                    cout << "aaa";
                    return false;
                }
                if(i > 0) {
                    if(s[i-1] != 'e' && s[i-1] != 'E') {
                        cout << "aaaa";
                        return false;
                    }
                }
                
                plmi++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};