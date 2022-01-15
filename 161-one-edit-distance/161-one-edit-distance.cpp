class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.length() == t.length() && s==t) {
            return false;
        }
        if(abs(int(s.length() - t.length())) > 1) {
            return false;
        }
        if(s.length()<t.length()) {
            string a=s;
            s=t;
            t=a;
        }
        for(int i=0;i<t.length();i++) {
            if(s[i] != t[i]) {
                if(s.length()==t.length()) {
                    return s.substr(i+1) == t.substr(i+1);
                } else {
                    return s.substr(i+1) == t.substr(i);
                }
            }
        }
        //out of for loop - all characters of is in s string
        return true;
    }
};