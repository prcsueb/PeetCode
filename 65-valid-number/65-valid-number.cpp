class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool e = false;
        int plmi = 0;
        int slen = s.length();
        
        for(int i=0;i<slen;i++) {
            cout << s[i] << endl;
            if(s[i] >= '0' && s[i] <= '9') {
                digit = true;
            } else if(s[i] == '+' || s[i] == '-') {
                if(plmi > 1) {
                    return false;
                }
                if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')) {
                    return false;
                }
                if(i == slen-1) {
                    return false;
                }
                plmi++;
            } else if(s[i] == '.') {
                //1.can't contain miltiple dots
                //2.e can not occurs after dot
                //3.dot can't be last character of the string
                //4.if there are no digits then also false
                if(dot == true || e == true) {
                    return false;
                }
                if(i == slen-1 && !digit) {
                    cout << "x";
                    return false;
                }
                dot = true;
            } else if(s[i] == 'e' || s[i] == 'E') {
                if(e || !digit || i == s.length()-1){
                    return false;
                }
                e = true;
            } else {
                return false;
            }
        }
        
        return true;
    }
};