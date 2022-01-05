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
                //1.there can be only 1 + or -
                //2.can't occur at the end
                //3.it can only occur after e OR starting of the string
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
                //2.dot can not occurs after e
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
                //1.multiple e's not allowed
                //2.e can't occur at the end
                //3. e9 OR .e1 - if e occured then there should atleaset one digit before
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