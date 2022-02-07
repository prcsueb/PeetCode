class Solution {
public:
    char findTheDifference(string s, string t) {
        int c = 0;
        for(int i=0;i<s.length();i++) {
            c = c ^ s[i];
        }
        for(int i=0;i<t.length();i++) {
            c = c ^ t[i];
        }
        
        return char(c);
    }
};