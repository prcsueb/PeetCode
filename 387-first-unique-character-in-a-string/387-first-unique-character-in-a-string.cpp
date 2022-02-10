class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> chars(26,0);
        for(int i=0;i<s.length();i++) {
            chars[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++) {
            if(chars[s[i]-'a']==1) {
                return i;
            }
        }
        
        return -1;
    }
};