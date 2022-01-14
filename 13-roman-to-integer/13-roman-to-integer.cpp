class Solution {
public:
    int romanToInt(string s) {
        /*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
        */
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int slen = s.length();
        int result=mp[s[slen-1]];
        for(int i=slen-2;i>=0;i--) {
            if(mp[s[i]] < mp[s[i+1]]) {
                result -= mp[s[i]];
            } else {
                result += mp[s[i]];
            }
        }
        return result;
    }
};